using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading;
using NUnit.Framework;

namespace PipeStream.Tests
{
	/// <summary>
	/// Tests for the PipeStream class.
	/// </summary>
	[TestFixture]
	public class PipeStreamTests
	{
		#region Private Variables

		/// <summary>
		/// Bridge stream object to use for multi-threaded read/write testing.
		/// </summary>
		private PipeStream mPipeStream;

		/// <summary>
		/// The string read from a threaded read process.
		/// </summary>
		private string mReadString = "";

		/// <summary>
		/// The total length of writes for a threaded writing process.
		/// </summary>
		private int mTotalWriteLength = -1;

		/// <summary>
		/// Some non-random text data to test with.
		/// </summary>
		private const string mTestString =
			@"LO, praise of the prowess of people-kings" +
			@"of spear-armed Danes, in days long sped," +
			@"we have heard, and what honor the athelings won!" +
			@"Oft Scyld the Scefing from squadroned foes," +
			@"from many a tribe, the mead-bench tore," +
			@"awing the earls. Since erst he lay" +
			@"friendless, a foundling, fate repaid him:" +
			@"for he waxed under welkin, in wealth he throve," +
			@"till before him the folk, both far and near," +
			@"who house by the whale-path, heard his mandate," +
			@"gave him gifts: a good king he!" +
			@"To him an heir was afterward born," +
			@"a son in his halls, whom heaven sent" +
			@"to favor the folk, feeling their woe" +
			@"that erst they had lacked an earl for leader" +
			@"so long a while; the Lord endowed him," +
			@"the Wielder of Wonder, with world's renown." +
			@"Famed was this Beowulf:1 far flew the boast of him," +
			@"son of Scyld, in the Scandian lands." +
			@"So becomes it a youth to quit him well" +
			@"with his father's friends, by fee and gift," +
			@"that to aid him, aged, in after days," +
			@"come warriors willing, should war draw nigh," +
			@"liegemen loyal: by lauded deeds" +
			@"shall an earl have honor in every clan." +
			@"Forth he fared at the fated moment," +
			@"sturdy Scyld to the shelter of God." +
			@"Then they bore him over to ocean's billow," +
			@"loving clansmen, as late he charged them," +
			@"while wielded words the winsome Scyld," +
			@"the leader beloved who long had ruled...." +
			@"In the roadstead rocked a ring-dight vessel," +
			@"ice-flecked, outbound, atheling's barge:" +
			@"there laid they down their darling lord" +
			@"on the breast of the boat, the breaker-of-rings,2" +
			@"by the mast the mighty one. Many a treasure" +
			@"fetched from far was freighted with him." +
			@"No ship have I known so nobly dight" +
			@"with weapons of war and weeds of battle," +
			@"with breastplate and blade: on his bosom lay" +
			@"a heaped hoard that hence should go" +
			@"far o'er the flood with him floating away." +
			@"No less these loaded the lordly gifts," +
			@"thanes' huge treasure, than those had done" +
			@"who in former time forth had sent him" +
			@"sole on the seas, a suckling child." +
			@"High o'er his head they hoist the standard," +
			@"a gold-wove banner; let billows take him," +
			@"gave him to ocean. Grave were their spirits," +
			@"mournful their mood. No man is able" +
			@"to say in sooth, no son of the halls," +
			@"no hero 'neath heaven, -- who harbored that freight!" +
			@"NOW Beowulf bode in the burg of the Scyldings," +
			@"leader beloved, and long he ruled" +
			@"in fame with all folk, since his father had gone" +
			@"away from the world, till awoke an heir," +
			@"haughty Healfdene, who held through life," +
			@"sage and sturdy, the Scyldings glad." +
			@"Then, one after one, there woke to him," +
			@"to the chieftain of clansmen, children four:" +
			@"Heorogar, then Hrothgar, then Halga brave;" +
			@"and I heard that -- was --'s queen," +
			@"the Heathoscylfing's helpmate dear." +
			@"To Hrothgar was given such glory of war," +
			@"such honor of combat, that all his kin" +
			@"obeyed him gladly till great grew his band" +
			@"of youthful comrades. It came in his mind" +
			@"to bid his henchmen a hall uprear," +
			@"a master mead-house, mightier far" +
			@"than ever was seen by the sons of earth," +
			@"and within it, then, to old and young" +
			@"he would all allot that the Lord had sent him," +
			@"save only the land and the lives of his men." +
			@"Wide, I heard, was the work commanded," +
			@"for many a tribe this mid-earth round," +
			@"to fashion the folkstead. It fell, as he ordered," +
			@"in rapid achievement that ready it stood there," +
			@"of halls the noblest: Heorot1 he named it" +
			@"whose message had might in many a land." +
			@"Not reckless of promise, the rings he dealt," +
			@"treasure at banquet: there towered the hall," +
			@"high, gabled wide, the hot surge waiting" +
			@"of furious flame.2 Nor far was that day" +
			@"when father and son-in-law stood in feud" +
			@"for warfare and hatred that woke again.3" +
			@"With envy and anger an evil spirit" +
			@"endured the dole in his dark abode," +
			@"that he heard each day the din of revel" +
			@"high in the hall: there harps rang out," +
			@"clear song of the singer. He sang who knew4" +
			@"tales of the early time of man," +
			@"how the Almighty made the earth," +
			@"fairest fields enfolded by water," +
			@"set, triumphant, sun and moon" +
			@"for a light to lighten the land-dwellers," +
			@"and braided bright the breast of earth" +
			@"with limbs and leaves, made life for all" +
			@"of mortal beings that breathe and move." +
			@"So lived the clansmen in cheer and revel" +
			@"a winsome life, till one began" +
			@"to fashion evils, that field of hell." +
			@"Grendel this monster grim was called," +
			@"march-riever5 mighty, in moorland living," +
			@"in fen and fastness; fief of the giants" +
			@"the hapless wight a while had kept" +
			@"since the Creator his exile doomed." +
			@"On kin of Cain was the killing avenged" +
			@"by sovran God for slaughtered Abel." +
			@"Ill fared his feud,6 and far was he driven," +
			@"for the slaughter's sake, from sight of men." +
			@"Of Cain awoke all that woful breed," +
			@"Ettins7 and elves and evil-spirits," +
			@"as well as the giants that warred with God" +
			@"weary while: but their wage was paid them!" +
			@"WENT he forth to find at fall of night" +
			@"that haughty house, and heed wherever" +
			@"the Ring-Danes, outrevelled, to rest had gone." +
			@"Found within it the atheling band" +
			@"asleep after feasting and fearless of sorrow," +
			@"of human hardship. Unhallowed wight," +
			@"grim and greedy, he grasped betimes," +
			@"wrathful, reckless, from resting-places," +
			@"thirty of the thanes, and thence he rushed" +
			@"fain of his fell spoil, faring homeward," +
			@"laden with slaughter, his lair to seek." +
			@"Then at the dawning, as day was breaking," +
			@"the might of Grendel to men was known;" +
			@"then after wassail was wail uplifted," +
			@"loud moan in the morn. The mighty chief," +
			@"atheling excellent, unblithe sat," +
			@"labored in woe for the loss of his thanes," +
			@"when once had been traced the trail of the fiend," +
			@"spirit accurst: too cruel that sorrow," +
			@"too long, too loathsome. Not late the respite;" +
			@"with night returning, anew began" +
			@"ruthless murder; he recked no whit," +
			@"firm in his guilt, of the feud and crime." +
			@"They were easy to find who elsewhere sought" +
			@"in room remote their rest at night," +
			@"bed in the bowers,1 when that bale was shown," +
			@"was seen in sooth, with surest token, --" +
			@"the hall-thane's2 hate. Such held themselves" +
			@"far and fast who the fiend outran!" +
			@"Thus ruled unrighteous and raged his fill" +
			@"one against all; until empty stood" +
			@"that lordly building, and long it bode so." +
			@"Twelve years' tide the trouble he bore," +
			@"sovran of Scyldings, sorrows in plenty," +
			@"boundless cares. There came unhidden" +
			@"tidings true to the tribes of men," +
			@"in sorrowful songs, how ceaselessly Grendel" +
			@"harassed Hrothgar, what hate he bore him," +
			@"what murder and massacre, many a year," +
			@"feud unfading, -- refused consent" +
			@"to deal with any of Daneland's earls," +
			@"make pact of peace, or compound for gold:" +
			@"still less did the wise men ween to get" +
			@"great fee for the feud from his fiendish hands." +
			@"But the evil one ambushed old and young" +
			@"death-shadow dark, and dogged them still," +
			@"lured, or lurked in the livelong night" +
			@"of misty moorlands: men may say not" +
			@"where the haunts of these Hell-Runes3 be." +
			@"Such heaping of horrors the hater of men," +
			@"lonely roamer, wrought unceasing," +
			@"harassings heavy. O'er Heorot he lorded," +
			@"gold-bright hall, in gloomy nights;" +
			@"and ne'er could the prince4 approach his throne," +
			@"-- 'twas judgment of God, -- or have joy in his hall." +
			@"Sore was the sorrow to Scyldings'-friend," +
			@"heart-rending misery. Many nobles" +
			@"sat assembled, and searched out counsel" +
			@"how it were best for bold-hearted men" +
			@"against harassing terror to try their hand." +
			@"Whiles they vowed in their heathen fanes" +
			@"altar-offerings, asked with words5" +
			@"that the slayer-of-souls would succor give them" +
			@"for the pain of their people. Their practice this," +
			@"their heathen hope; 'twas Hell they thought of" +
			@"in mood of their mind. Almighty they knew not," +
			@"Doomsman of Deeds and dreadful Lord," +
			@"nor Heaven's-Helmet heeded they ever," +
			@"Wielder-of-Wonder. -- Woe for that man" +
			@"who in harm and hatred hales his soul" +
			@"to fiery embraces; -- nor favor nor change" +
			@"awaits he ever. But well for him" +
			@"that after death-day may draw to his Lord," +
			@"and friendship find in the Father's arms!";

		#endregion

		#region Tests

		/// <summary>
		/// Tests
		/// </summary>
		[Test]
		public void ReadWriteSingleThreadTests()
		{
			mPipeStream = new PipeStream();
			WriteThread();
			ReadThread();
			Assert.AreEqual(mTestString, mReadString);
		}

		/// <summary>
		/// Tests the PipeStream by reading and writing in separate threads.
		/// </summary>
		[Test]
		public void ReadWriteMultiThreadTests()
		{
			mPipeStream = new PipeStream();

			var readThread = new Thread(ReadThread);
			var writeThread = new Thread(WriteThread);
			readThread.Start();
			writeThread.Start();

			writeThread.Join();
			readThread.Join();
			Assert.AreEqual(mTestString, mReadString);
		}

		/// <summary>
		/// Functionally tests the PipeStream by reading and writing in separate threads.
		/// </summary>
		[Test]
		public void ReadWriteWithSeveralStreamsMultiThreadTests()
		{
			// Test with block on
			mPipeStream = new PipeStream();
			mPipeStream.MaxBufferLength = 1025;
			mPipeStream.BlockLastReadBuffer = true; // block the read() if it will empty the stream

			var readThread = new Thread(ReadThread);
			var writeThread = new Thread(WriteWithSeveralStreamsThread);
			readThread.Start();
			writeThread.Start();

			writeThread.Join();
			mPipeStream.BlockLastReadBuffer = false; // all the writing is done, so don't block anymore
			readThread.Join();
			Assert.AreEqual(mTotalWriteLength, mReadString.Length);

			// Test with block off
			mPipeStream = new PipeStream();
			mPipeStream.BlockLastReadBuffer = false;

			readThread = new Thread(ReadThread);
			writeThread = new Thread(WriteWithSeveralStreamsThread);
			readThread.Start();
			writeThread.Start();

			writeThread.Join();
			readThread.Join();

			// this next method is non-deterministic - it may end up reading the entire buffer,
			// but I wouldn't bet on it.
			Debug.WriteLine(String.Format("mTotalWriteLength={0}, mReadString.Length={1}", mTotalWriteLength, mReadString.Length));
			//Assert.AreNotEqual(mTotalWriteLength, mReadString.Length);
		}

		#endregion

		#region Thread methods

		/// <summary>
		/// Read function for the multithread test
		/// </summary>
		private void ReadThread()
		{
			var sr = new StreamReader(mPipeStream);
			mReadString = ReadStringFromStreamReader(sr);
		}

		/// <summary>
		/// Write function for the multithread test - writes one stream to mPipeStream
		/// </summary>
		private void WriteThread()
		{
			using (var sw = new StreamWriter(mPipeStream))
			{
				WriteDataToStreamWriter(sw, mTestString);
			}
		}

		/// <summary>
		/// Write several streams to mPipeStream
		/// </summary>
		private void WriteWithSeveralStreamsThread()
		{
			mTotalWriteLength = 0;

			for (int i = 0; i < 10; i++)
			{
				using (var sw = new StreamWriter(mPipeStream))
				{
					for (int j = 0; j < 20; j++)
						mTotalWriteLength += WriteDataToStreamWriter(sw, mTestString);
					Thread.Sleep(100);
				}
			}
		}

		#endregion

		#region Read and Write Methods

		/// <summary>
		/// Reads the string from the passed in stream reader.
		/// </summary>
		/// <param name="sr">The stream reader.</param>
		/// <returns></returns>
		private static string ReadStringFromStreamReader(StreamReader sr)
		{
			var sb = new StringBuilder();
			var buffer = new char[80];
			while (!sr.EndOfStream)
			{
				int readLength = sr.Read(buffer, 0, buffer.Length);
				sb.Append(buffer, 0, readLength);
			}
			return sb.ToString();
		}

		/// <summary>
		/// Writes the string to stream writer.
		/// </summary>
		/// <param name="sw">The sw.</param>
		/// <param name="str">The STR.</param>
		/// <returns></returns>
		private static int WriteDataToStreamWriter(TextWriter sw, string str)
		{
			const int writeSize = 127;
			for (int i = 0; i < str.Length; i += writeSize)
			{
				// select a substring of characters from the input string
				string substring = str.Substring(i, (i + writeSize < str.Length) ? writeSize : str.Length - i);
				sw.Write(substring.ToCharArray(), 0, substring.Length);
			}
			return str.Length;
		}

		#endregion

		#region Time Trial Testing


		/*
		/// <summary>
		/// Compare the length of time to use PipeStream vs MemoryStream.
		/// </summary>
		[Test]
		public void TimeComparisonTest()
		{
			const int iterations = 11024;
			const int arraySize = 11024;
			var bytes = new byte[arraySize];
			var readBytes = new byte[arraySize];

			var h = new HiPerfTimer();

			h.Start();
			var bs = new PipeStream();
			for (int i = 0; i < iterations; i++)
			{
				bs.Write(bytes, 0, bytes.Length);
			}
			for (int i = 0; i < iterations; i++)
			{
				bs.Read(readBytes, 0, bytes.Length);
			}
			h.Stop();
			Debug.WriteLine(string.Format("PipeStream: {0}s", h.Duration));

			h = new HiPerfTimer();
			h.Start();
			Stream s = new MemoryStream();
			for (int i = 0; i < iterations; i++)
			{
				s.Write(bytes, 0, bytes.Length);
			}
			for (int i = 0; i < iterations; i++)
			{
				s.Read(readBytes, 0, bytes.Length);
			}
			h.Stop();
			Debug.WriteLine(string.Format("MemoryStream: {0}s", h.Duration));
		}
		 * */
		#endregion
	}
}
