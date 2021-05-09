import { ModuleTask } from './ModuleTask';
import { GroupModule } from './GroupModule';


export interface Module {
    moduleID: number;
    moduleName: string;

    tasks: ModuleTask[];
    groupModules: GroupModule[];
    
}

