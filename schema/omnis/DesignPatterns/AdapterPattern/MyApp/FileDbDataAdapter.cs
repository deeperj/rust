using System.Data;
using System.Data.Common;
using FileDb;

namespace MyApp
{
    public class FileDbDataAdapter : DbDataAdapter
    {
        private readonly string tableName;

        public FileDbDataAdapter(string tableName)
        {
            this.tableName = tableName;
        }

        public override int Fill(DataSet dataSet)
        {
            var dt = new DataTable();

            FileDbTable fileDbTable = new FileDb.FileDb().GetTable(tableName);

            foreach (var row in fileDbTable)
            {
                DataRow dataRow = dt.NewRow();

                foreach (var name in row.Keys)
                {
                    if (!dt.Columns.Contains(name))
                        dt.Columns.Add(name);                        

                    dataRow[name] = row[name];
                }

                dt.Rows.Add(dataRow);
            }

            dataSet.Tables.Add(dt);

            return dt.Rows.Count;
        }
    }
}