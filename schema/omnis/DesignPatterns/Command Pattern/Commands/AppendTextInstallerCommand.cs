using System;
using System.IO;

namespace Command_Pattern
{
    public class AppendTextInstallerCommand : InstallerCommand
    {
        private readonly string filePath;
        private readonly string text;

        public AppendTextInstallerCommand(string filePath, string text)
        {
            this.filePath = filePath;
            this.text = text;
        }

        public override void Execute()
        {
            using (StreamWriter writer = File.AppendText(filePath))
                writer.WriteLine(text);

            Console.WriteLine("Appended '{0}' to file '{1}'", text, filePath);
        }

        public override void Rollback()
        {
            var fileText = File.ReadAllText(filePath);

            if (fileText.EndsWith(text + "\r\n"))
            {
                File.WriteAllText(filePath, fileText.Substring(0, fileText.Length - text.Length - 2));
                Console.WriteLine("Removed '{0}' from file '{1}'", text, filePath);
            }
        }
    }
}