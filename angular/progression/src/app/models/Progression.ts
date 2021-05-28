import { Student } from './Student';
import { ModuleTask } from './ModuleTask';

export interface Progression {
    progressionID?: number | null;
    moduleTaskID: number;
    studentID: number;
    taskAssessment: number;
    completed: boolean;
    dueDate: Date | string;
    comments: string;

    task?: ModuleTask | null;
    student?: Student | null;
}
