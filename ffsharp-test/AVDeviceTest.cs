using ffsharp;
using NUnit.Framework;

namespace ffsharp_test
{

    [TestFixture]
    public class AVDeviceTest
    {

        [TestFixtureSetUp]
        public void Setup()
        {
            AVDevice.RegisterAll();
        }

        [Test]
        public void TestFormatLists()
        {
            var audioInput = AVDevice.AudioInputDevices;
            var audioOutput = AVDevice.AudioOutputDevices;
            var videoInput = AVDevice.VideoInputDevices;
            var videoOutput = AVDevice.VideoOutputDevices;
            Assert.NotNull(audioInput);
            Assert.NotNull(audioOutput);
            Assert.NotNull(videoInput);
            Assert.NotNull(videoOutput);
            Assert.AreEqual(1, audioInput.Count);
            Assert.AreEqual(0, audioOutput.Count);
            Assert.AreEqual(4, videoInput.Count);
            Assert.AreEqual(3, videoOutput.Count);
        }
        
    }

}