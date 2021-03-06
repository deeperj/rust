import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { HttpClientModule } from '@angular/common/http';
import { NoopAnimationsModule } from '@angular/platform-browser/animations';
import {MatToolbarModule} from '@angular/material/toolbar';
import {MatIconModule} from '@angular/material/icon';
import {MatTabsModule} from '@angular/material/tabs';
import {MatListModule} from '@angular/material/list';
import {MatExpansionModule} from '@angular/material/expansion';
import {MatButtonModule} from '@angular/material/button';
import {MatDividerModule} from '@angular/material/divider';
import {MatSnackBarModule} from '@angular/material/snack-bar';
import {MatTableModule} from '@angular/material/table';
import {MatMenuModule} from '@angular/material/menu';
import {MatInputModule} from '@angular/material/input';
import {MatDialogModule} from '@angular/material/dialog';
import {MatCheckboxModule} from '@angular/material/checkbox';
import {MatProgressSpinnerModule} from '@angular/material/progress-spinner';
import {MatProgressBarModule} from '@angular/material/progress-bar';


import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HeaderComponent } from './components/header/header.component';
import { MainMenuComponent } from './components/main-menu/main-menu.component';
import { ProgressionComponent } from './components/progression/progression.component';
import { DebugService } from './services/debug.service';
import { StringConcatPipe } from './pipes/stringconcatpipe';
import { MsgBoxComponent } from './components/msg-box/msg-box.component';
import { ProgressReportComponent } from './components/progress-report/progress-report.component';
import { AttendanceReportComponent } from './components/attendance-report/attendance-report.component';
import { FileuploadComponent } from './widgets/fileupload.component';
import { AssessmentComponent } from './components/assessment/assessment.component';
import { SumAssessmentComponent } from './components/sum-assessment/sum-assessment.component';
import { FormAssessmentComponent } from './components/form-assessment/form-assessment.component';
import { AllAssessmentComponent } from './components/all-assessment/all-assessment.component';
import { NgxsModule } from '@ngxs/store';
import { ProgressionState } from './store/progress.state';
import { NgxsReduxDevtoolsPluginModule } from '@ngxs/devtools-plugin';
import { NgxsLoggerPluginModule } from '@ngxs/logger-plugin';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    MainMenuComponent,
    ProgressionComponent,
    StringConcatPipe,
    MsgBoxComponent,
    ProgressReportComponent,
    AttendanceReportComponent,
    FileuploadComponent,
    AssessmentComponent,
    SumAssessmentComponent,
    FormAssessmentComponent,
    AllAssessmentComponent,
    
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    BrowserAnimationsModule,
    HttpClientModule,
    MatToolbarModule,
    MatIconModule,
    MatTabsModule,
    MatListModule,
    MatExpansionModule,
    MatButtonModule,
    MatDividerModule,
    MatSnackBarModule,
    MatTableModule,
    MatMenuModule,
    MatInputModule,
    MatDialogModule,
    MatCheckboxModule,
    MatProgressSpinnerModule,
    MatProgressBarModule,
    NgxsModule.forRoot([
      ProgressionState
    ]),
    NgxsReduxDevtoolsPluginModule.forRoot(),
    NgxsLoggerPluginModule.forRoot()
  ],
  providers: [
    DebugService,  
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
