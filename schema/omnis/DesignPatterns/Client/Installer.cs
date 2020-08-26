using System;

namespace Command_Pattern
{
    public class Installer
    {
        private readonly InstallerCommand installerCommand;

        public Installer(InstallerCommand installerCommand)
        {
            this.installerCommand = installerCommand;
        }

        public void Install()
        {
            try
            {
                Console.WriteLine("Installing...\n");
                installerCommand.Execute();
            }
            catch (Exception)
            {
                Console.WriteLine("\nRolling Back...\n");
                installerCommand.Rollback();
            }
        }
    }


}
