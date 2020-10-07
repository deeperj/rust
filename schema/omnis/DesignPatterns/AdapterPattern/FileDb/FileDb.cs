
using System.Collections.Generic;
using System.IO;

namespace FileDb
{
    public class FileDbTable : List<FileDbRow> {}
    public class FileDbRow : Dictionary<string, string> {}

    public class FileDb
    {
        public FileDbTable GetTable(string tableName)
        {
            var lines = File.ReadAllLines(tableName);

            var fileDbTable = new FileDbTable();
 
            foreach (var line in lines)
            {
                var row = new FileDbRow();

                foreach (var keyValues in line.Split(';'))
                {
                    var keyValue = keyValues.Split('=');
                    var key = keyValue[0];
                    var value = keyValue[1];

                    row[key] = value;
                }

                fileDbTable.Add(row);
            }

            return fileDbTable;
        }
    }

}
