using System;
using System.Collections.Generic;

namespace Command_Pattern
{
    class Program
    {
        //static void Main()
        //{
        //    var command1 = new CreateFileInstallerCommand(@"c:\temp\temp.txt");
        //    var command2 = new AppendTextInstallerCommand(@"c:\temp\log.txt", "Line 1");
        //    var command3 = new CreateRegistryKeyInstallerCommand("AndreaAn");
            
        //    new Installer(command1).Install();
        //    new Installer(command2).Install();
        //    new Installer(command3).Install();

        //    Console.ReadKey();
        //}

        static void Main()
        {
            var transaction = new TransactionInstallerCommand(new List<InstallerCommand>
                              {
                                  new CreateFileInstallerCommand(@"c:\temp\temp.txt"),
                                  new AppendTextInstallerCommand(@"c:\temp\log.txt", "Line 1"),
                                  new AppendTextInstallerCommand(@"c:\temp\log.txt", "Line 2"),
                                  new CreateRegistryKeyInstallerCommand("AndreaAn"),
                                  new ExceptionInstallerCommand(),
                                  new CreateFileInstallerCommand(@"c:\temp\file.txt"),
                              });

            var installer = new Installer(transaction);
            installer.Install();

            Console.ReadKey();
        }
    }
}
