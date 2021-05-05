import { ModuleTask } from './ModuleTask';
import { GroupModule } from './GroupModule';


export interface Module {
    moduleId: number;
    moduleName: string;

    tasks: ModuleTask[];
    groupModules: GroupModule[];
    
}

