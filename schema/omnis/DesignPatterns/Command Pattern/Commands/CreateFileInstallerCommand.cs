using System;
using System.IO;

namespace Command_Pattern
{
    public class CreateFileInstallerCommand : InstallerCommand
    {
        private readonly string filePath;

        public CreateFileInstallerCommand(string filePath)
        {
            this.filePath = filePath;
        }

        public override void Execute()
        {
            using (File.Create(filePath)) {}

            Console.WriteLine("Created file '{0}'", filePath);
        }

        public override void Rollback()
        {
            File.Delete(filePath);

            Console.WriteLine("Deleted file '{0}'", filePath);
        }
    }


}