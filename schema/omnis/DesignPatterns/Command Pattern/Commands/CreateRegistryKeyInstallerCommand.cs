using System;
using Microsoft.Win32;

namespace Command_Pattern
{
    public class CreateRegistryKeyInstallerCommand : InstallerCommand
    {
        private readonly string key;

        public CreateRegistryKeyInstallerCommand(string key)
        {
            this.key = key;
        }

        public override void Execute()
        {
            using (Registry.CurrentUser.CreateSubKey(key)) {}
            Console.WriteLine("Created registry key '{0}'", key);
        }

        public override void Rollback()
        {
            Registry.CurrentUser.DeleteSubKey(key);
            Console.WriteLine("Deleted registry key '{0}'", key);
        }
    }


}