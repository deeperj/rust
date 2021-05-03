import { ModuleTask } from './ModuleTask';
import { GroupModule } from './GroupModule';


export interface Module {
    ModuleID: number;
    ModuleName: string;

    Tasks: ModuleTask[];
    GroupModules: GroupModule[];
    
}

