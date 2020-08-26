using System.Runtime.InteropServices;
using System.ComponentModel;
using System.Threading;

namespace PipeStream.Tests
{
	/// <summary>
	/// High-Performance Timer in C#.
	/// Provides exact time measurement in your applications. 
	/// </summary>
	/// <remarks>
	/// By Daniel Strigl http://www.codeproject.com/KB/cs/highperformancetimercshar.aspx
	/// </remarks>
    internal class HiPerfTimer
    {
        [DllImport("Kernel32.dll")]
        private static extern bool QueryPerformanceCounter(out long lpPerformanceCount);  

		[DllImport("Kernel32.dll")]
		private static extern bool QueryPerformanceFrequency(out long lpFrequency);
		
		private long startTime, stopTime;
		private readonly long freq;
		
		/// <summary>
		/// Initializes a new instance of the <see cref="HiPerfTimer"/> class.
		/// </summary>
		public HiPerfTimer()
		{
            startTime = 0;
            stopTime  = 0;

            if (QueryPerformanceFrequency(out freq) == false)
            {
                // high-performance counter not supported 
                throw new Win32Exception(); 
            }
		}
		
		/// <summary>
		/// Start the timer.
		/// </summary>
		public void Start()
		{
            // lets do the waiting threads there work
            Thread.Sleep(0);  

			QueryPerformanceCounter(out startTime);
		}
		
		/// <summary>
		/// Stop the timer.
		/// </summary>
		public void Stop()
		{
		    QueryPerformanceCounter(out stopTime);
		}
		
		/// <summary>
		/// Returns the duration of the timer (in seconds).
		/// </summary>
		/// <value>The duration (in seconds).</value>
        public double Duration
        {
        	get
        	{
            	return (stopTime - startTime) / (double) freq;
            }
        }
	}
}
