using System;

namespace Command_Pattern
{
    public class ExceptionInstallerCommand : InstallerCommand
    {
        public override void Execute() { throw new Exception(); }
        public override void Rollback() { }
    }


}