import { Student } from './Student';
import { ModuleTask } from './ModuleTask';

export interface Progression {
    progressionId: number | null;
    moduleTaskId: number;
    studentId: number;
    taskAssessment: number;
    completed: boolean ;
    dueDate: Date | string;
    comments: string;

    task: ModuleTask | null;
    student: Student ;
}
