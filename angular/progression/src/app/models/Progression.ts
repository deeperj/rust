import { Student } from './Student';
import { ModuleTask } from './ModuleTask';

export interface Progression {
    progressionId: number;
    moduleTaskId: number;
    studentId: number;
    taskAssessment: number;
    completed: boolean | null;
    dueDate: Date | string;
    comments: string;

    task: ModuleTask;
    student: Student;
}
