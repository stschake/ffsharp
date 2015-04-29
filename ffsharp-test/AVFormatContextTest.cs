using System;
using ffsharp;
using NUnit.Framework;

namespace ffsharp_test
{

    [TestFixture]
    public class AVFormatContextTest
    {
        private AVFormatContext _context;

        [TestFixtureSetUp]
        public void Setup()
        {
            AVFormat.RegisterAll();
            _context = AVFormat.OpenInput("test.ts");
        }

        [Test]
        public void TestMetadata()
        {
            _context = AVFormat.OpenInput("test.mp3");
            Assert.AreEqual(5, _context.Metadata.Count());
            foreach (var entry in _context.Metadata)
            {
                if (entry.Key == "genre")
                    Assert.AreEqual("Acid", entry.Value);
                else
                    Assert.IsTrue(entry.Value.Contains("Test"));
            }
        }

        [Test]
        public void TestReadFrame()
        {
            int frames = 0;
            AVPacket packet = _context.ReadFrame();
            while ((packet = _context.ReadFrame()) != null)
                frames++;
            Assert.AreEqual(680, frames);
        }

        [Test]
        public void TestFindStreamInfo()
        {
            _context.FindStreamInfo();
            Assert.AreEqual(2, _context.NumberStreams);
        }

        [Test]
        public void TestFindBestStream()
        {
            _context.FindStreamInfo();
            Assert.AreEqual(AVMediaType.Audio, _context.FindBestStream(AVMediaType.Audio).CodecContext.CodecType);
            Assert.AreEqual(AVMediaType.Video, _context.FindBestStream(AVMediaType.Video).CodecContext.CodecType);
            Assert.AreEqual(null, _context.FindBestStream(AVMediaType.Subtitle));
        }

        [Test]
        public void TestGetStream()
        {
            _context.FindStreamInfo();
            int i = 0;
            for (; i < _context.NumberStreams; i++)
            {
                var stream = _context.GetStream(i);
                Assert.IsNotNull(stream);
            }
            Assert.Throws(typeof (IndexOutOfRangeException), () => _context.GetStream(i));
        }

    }

}