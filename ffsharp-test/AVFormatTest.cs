using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mime;
using System.Runtime.Versioning;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;
using ffsharp;

namespace ffsharp_test
{

    [TestFixture]
    public class AVFormatTest
    {
        [TestFixtureSetUp]
        public void Setup()
        {
            AVFormat.RegisterAll();
            AVFormat.NetworkInit();
        }

        [Test]
        public void TestFormatLists()
        {
            var inputFormats = AVFormat.InputFormats;
            var outputFormats = AVFormat.OutputFormats;
            Assert.NotNull(inputFormats);
            Assert.NotNull(outputFormats);
            Assert.AreEqual(237, inputFormats.Count);
            Assert.AreEqual(142, outputFormats.Count);
        }

        [Test]
        public void TestVersion()
        {
            Assert.IsTrue(AVFormat.MajorVersion >= 56);
            Assert.IsTrue(AVFormat.MinorVersion >= 31);
            Assert.IsTrue(AVFormat.MicroVersion >= 100);
            Assert.IsTrue(AVFormat.Version != 0);
        }

        [Test]
        public void TestOpenInput()
        {
            Assert.Throws(typeof (AVErrorException), () => AVFormat.OpenInput("nonexisting.file"));
            var context = AVFormat.OpenInput("test.ts");
            Assert.IsNotNull(context);
        }

    }
}
