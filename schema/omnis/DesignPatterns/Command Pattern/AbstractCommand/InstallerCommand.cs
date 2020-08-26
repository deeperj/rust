namespace Command_Pattern
{
    public abstract class InstallerCommand
    {
        public abstract void Execute();
        public abstract void Rollback();
    }

}