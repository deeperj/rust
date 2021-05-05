import { Module } from './Module';
import { Group } from './Group';

export interface GroupModule {
    id: number;
    groupId: number;
    moduleId: number;

    module: Module;
    group: Group;

}

