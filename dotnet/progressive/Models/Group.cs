using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace progressive.Models
{
    public enum Department
    {
        Science, 
        Engineering, 
        Computing,
        Business
    }

    public enum Pathway
    {
        ComputerSecurity, 
        ComputerSystemsEngineering, 
        ElectricalElectronicsEngineering,
        Nursing,
        MidWifery,
        ChemicalEngineering,
        AutomotiveEngineering,
        MechanicalEngineering,
        CyberSecurity,
        Pharmacy,
        Computing,
        SoftwareEngineering,
        BioMedicalScience
    }

    public class Group
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int GroupID { get; set; }
        public int BatchID { get; set; }
        public int GroupNumber { get; set; }
        public string GroupCode { get; set; }
        public Pathway Pathway { get; set; }
        public Department Department { get; set; }

        public Batch Batch { get; set; }

        public ICollection<Student> Students { get; set; }
        public ICollection<GroupModule> GroupModules { get; set; }
    }
}

