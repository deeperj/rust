import { TaskType, RPAGType } from './enums';
import { Module } from './Module';
import { Progression } from './Progression';

export interface ModuleTask {
    ModuleTaskID: number;
    ModuleID: number;
    Term: number;
    TaskType: TaskType;
    RPAGType: RPAGType;
    InSumRPAG: boolean;
    TaskName: string;
    Url: string;
    DueWeek: number;
    DueLesson: number;
    DueDate: Date | string | null;

    Module: Module;

    Progressions: Progression[];
}

    
