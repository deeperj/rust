import { TaskType, RPAGType } from './enums';
import { Module } from './Module';
import { Progression } from './Progression';

export interface ModuleTask {
    moduleTaskId: number;
    moduleId: number;
    term: number;
    taskType: TaskType;
    rpagType: RPAGType;
    inSumRpag: boolean;
    taskName: string;
    url: string;
    dueWeek: number;
    dueLesson: number;
    dueDate: Date | string | null;

    module: Module;

    Progressions: Progression[];
}

    
