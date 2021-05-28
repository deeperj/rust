import { Department, Pathway } from './enums';
import { Batch } from './Batch';
import { GroupModule } from './GroupModule';
import { Student } from './Student';

export interface Group {
    groupID: number;
    batchID: number;
    groupNumber: number;
    groupCode: string;
    pathway: Pathway;
    department: Department;
    taughtTerm: number;
    
    batch: Batch;

    students: Student[];
    groupModules: GroupModule[];
}
