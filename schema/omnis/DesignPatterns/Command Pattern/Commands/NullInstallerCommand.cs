namespace Command_Pattern
{
    public class NullInstallerCommand : InstallerCommand
    {
        public override void Execute() {}
        public override void Rollback() {}
    }
}