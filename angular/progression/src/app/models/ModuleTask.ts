import { TaskType, RPAGType } from './enums';
import { Module } from './Module';
import { Progression } from './Progression';

export interface ModuleTask {
    moduleTaskID: number;
    moduleId: number;
    taskType: TaskType;
    rpagType: RPAGType;
    inSumRpag: boolean;
    active: boolean;
    taskName: string;
    url: string;
    screenCastUrl: string;
    dueWeek: number;
    dueLesson: number;
    dueDate: Date | string | null;

    module: Module;

    Progressions: Progression[];
}

    
