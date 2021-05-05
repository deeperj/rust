import { Department, Pathway } from './enums';
import { Batch } from './Batch';
import { GroupModule } from './GroupModule';
import { Student } from './Student';

export interface Group {
    groupId: number;
    batchId: number;
    groupNumber: number;
    groupCode: string;
    pathway: Pathway;
    department: Department;

    batch: Batch;

    students: Student[];
    groupModules: GroupModule[];
}
