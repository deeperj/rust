import { Module } from './Module';
import { Group } from './Group';

export interface GroupModule {
    //    ID: number;
    GroupID: number;
    ModuleID: number;

    Module: Module;
    Group: Group;

}

