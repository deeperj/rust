using System.Collections.Generic;

namespace Command_Pattern
{
    public class TransactionInstallerCommand : InstallerCommand
    {
        private readonly List<InstallerCommand> tasks;
        private Stack<InstallerCommand> executedTasks;

        public TransactionInstallerCommand(List<InstallerCommand> tasks)
        {
            this.tasks = tasks;
        }

        public override void Execute()
        {
            executedTasks = new Stack<InstallerCommand>();

            foreach (InstallerCommand task in tasks)
            {
                executedTasks.Push(task);
                task.Execute();
            }

            executedTasks.Clear();
        }

        public override void Rollback()
        {
            while (executedTasks.Count > 0)
            {
                executedTasks.Pop().Rollback();
            }            
        }
    }
}
