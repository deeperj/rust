import { Student } from './Student';
import { ModuleTask } from './ModuleTask';

export interface Progression {
    ProgressionID: number;
    ModuleTaskID: number;
    StudentID: number;
    TaskAssessment: number;
    Completed: boolean | null;
    DueDate: Date | string;
    Comments: string;

    Task: ModuleTask;
    Student: Student;
}
