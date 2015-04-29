using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using ffsharp;
using NUnit.Framework;

namespace ffsharp_test
{

    [TestFixture]
    public class AVCodecContextTest
    {
        private AVFormatContext _formatContext;
        private AVCodecContext _codecContext;

        [TestFixtureSetUp]
        public void FixtureSetup()
        {
            AVFormat.RegisterAll();
        }

        [SetUp]
        public void Setup()
        {
            _formatContext = AVFormat.OpenInput("test.ts");
            _formatContext.FindStreamInfo();
            _codecContext = _formatContext.GetStream(0).CodecContext;
        }

        [Test]
        public void TestOpen()
        {
            Assert.IsNull(_codecContext.Codec);
            _codecContext.Open2(AVCodec.FindDecoder(_codecContext.CodecId));
            Assert.IsNotNull(_codecContext.Codec);
            Assert.AreEqual("h264", _codecContext.Codec.Name);
        }

        private static void PgmSave(String filename, AVFrame frame)
        {
            using (var f = File.Create(filename))
            {
                var fs = new StreamWriter(f, Encoding.ASCII);
                fs.Write("P5\n");
                fs.Write(frame.Width + " " + frame.Height + "\n");
                fs.Write("255\n");
                fs.Flush();
                var line = new byte[frame.Width];
                for (int i = 0; i < frame.Height; i++)
                {
                    Marshal.Copy(frame.GetData(0) + (i*frame.Width), line, 0, frame.Width);
                    fs.BaseStream.Write(line, 0, line.Length);
                }
                fs.Flush();
                fs.Close();
            }
        }

        [Test]
        public void TestDecode()
        {
            _codecContext.Open2(AVCodec.FindDecoder(_codecContext.CodecId));
            int frames = 0;
            AVPacket packet;
            var frame = new AVFrame();
 
            while ((packet = _formatContext.ReadFrame()) != null)
            {
                if (packet.StreamIndex != 0)
                    continue;
                bool picture = _codecContext.DecodeVideo2(packet, frame);
                if (!picture)
                    continue;

                frames++;

                // to check the frames visually, not part of normal test
                // PgmSave(frames + ".pgm", frame);
            }
            Assert.AreEqual(245, frames);
        }

        [Test]
        public void TestEncode()
        {
            AVLog.Callback += (level, msg) => Console.WriteLine(level + ": " + msg);
            AVLog.Level = (int) AVLogLevel.Trace;

            _codecContext.Open2(AVCodec.FindDecoder(_codecContext.CodecId));
            AVPacket packet;
            var frame = new AVFrame();

            var codec = AVCodec.FindEncoderByName("png");
            var encodeContext = new AVCodecContext(codec)
                                {
                                    PixelFormat = AVPixelFormat.RGB24,
                                    Width = _codecContext.Width,
                                    Height = _codecContext.Height
                                };
            encodeContext.Open2(codec);

            var convContext = SWSContext.GetContext(_codecContext.Width, _codecContext.Height, AVPixelFormat.YUV420P,
                AVPixelFormat.RGB24);
            var convBuffer = new AVPicture(AVPixelFormat.RGB24, _codecContext.Width, _codecContext.Height).AsFrame();

            int frameCounter = 0;
            int readCounter = 0;
            while ((packet = _formatContext.ReadFrame()) != null)
            {
                if (packet.StreamIndex != 0)
                    continue;
                bool pic = _codecContext.DecodeVideo2(packet, frame);
                if (!pic)
                    continue;

                readCounter++;
                convContext.Scale(frame, convBuffer, 0, _codecContext.Height);

                var outPacket = encodeContext.EncodeVideo2(convBuffer);
                if (outPacket != null)
                {
                    frameCounter++;

                    // for checking the frames, not part of normal test
                    //var data = new byte[outPacket.Size];
                    //Marshal.Copy(outPacket.Data, data, 0, data.Length);
                    //File.WriteAllBytes((frameCounter++) + ".png", data);
                }
            }

            Assert.AreEqual(readCounter, frameCounter);
            Assert.AreEqual(245, readCounter);

            encodeContext.Close();
            _codecContext.Close();
        }
    }

}