import { Department, Pathway } from './enums';
import { Batch } from './Batch';

export interface Group {
    GroupID: number;
    BatchID: number;
    GroupNumber: number;
    GroupCode: string;
    Pathway: Pathway;
    Department: Department;

    Batch: Batch;

    Students: Student[];
    GroupModules: GroupModule[];
}
