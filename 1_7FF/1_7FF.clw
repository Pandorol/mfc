; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COnlineSystem1
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "1_7FF.h"
LastPage=0

ClassCount=19
Class1=CMy1_7FFApp
Class2=CMy1_7FFDoc
Class3=CMy1_7FFView
Class4=CMainFrame

ResourceCount=14
Resource1=IDD_EEGWAVE_DIALOG
Resource2=IDD_CONNECTION_STATUS_DIALOG
Resource3=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CConnectDeviceDialog
Resource4=IDD_PARADIGM_SHOW
Class7=CConnectionStatusDialog
Class8=CImpedanceDetectiveDialog
Resource5=IDD_NEW_ACTIVITY_DIALOG
Class9=CChannelsSetupDialog
Resource6=IDD_DEVICE_INFO_DIALOG
Class10=CParadigmSetupDialog
Resource7=IDD_CONNECT_DEVICE_DIALOG
Class11=CNewActivityDialog
Resource8=IDD_TCPIP_SETUP_DIALOG
Class12=CAddActivityDialog
Class13=CWaveView
Resource9=IDR_MAINFRAME
Class14=CDeviceInfoDialog
Resource10=IDD_PARADIGM_SETUP_DIALOG
Class15=CParadigmShowDialog
Resource11=IDD_ADD_ACTIVITY_DIALOG
Class16=CEEGWaveDialog
Class17=CDrawPand
Resource12=IDD_IMPEDANCE_DETECTIVE_DIALOG
Class18=CTCPIPSetupDialog
Resource13=IDD_CHANNELS_SETUP_DIALOG
Class19=COnlineSystem1
Resource14=IDD_ONLINESYSTEM1_DIALOG

[CLS:CMy1_7FFApp]
Type=0
HeaderFile=1_7FF.h
ImplementationFile=1_7FF.cpp
Filter=N

[CLS:CMy1_7FFDoc]
Type=0
HeaderFile=1_7FFDoc.h
ImplementationFile=1_7FFDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CMy1_7FFView]
Type=0
HeaderFile=1_7FFView.h
ImplementationFile=1_7FFView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_MENU_ONLINESYSTEM1




[CLS:CAboutDlg]
Type=0
HeaderFile=1_7FF.cpp
ImplementationFile=1_7FF.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_MENU_CONNECTION_STATUS
Command2=ID_MENU_DEVICE_INFO
Command3=ID_MENU_EXIT
Command4=ID_MENU_IMPEDANCE_DETECTIVE
Command5=ID_MENU_CHANNELS_SETUP
Command6=ID_MENU_PARADIGM_SETUP
Command7=ID_MENU_DATASAVEDIR
Command8=ID_MENU_START_COLLECT
Command9=ID_MENU_RECWAVE_MONITOR
Command10=ID_MENU_EEG_MONITOR
Command11=ID_MENU_OPEN_SIGNAL
Command12=ID_MENU_TCPIP_SETUP
Command13=ID_MENU_ONLINESYSTEM1
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_CONNECT_DEVICE_DIALOG]
Type=1
Class=CConnectDeviceDialog
ControlCount=2
Control1=ID_CONNECT,button,1342242817
Control2=ID_CANCEL,button,1342242816

[CLS:CConnectDeviceDialog]
Type=0
HeaderFile=ConnectDeviceDialog.h
ImplementationFile=ConnectDeviceDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CConnectDeviceDialog
VirtualFilter=dWC

[DLG:IDD_CONNECTION_STATUS_DIALOG]
Type=1
Class=CConnectionStatusDialog
ControlCount=2
Control1=ID_BTN_OK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:CConnectionStatusDialog]
Type=0
HeaderFile=ConnectionStatusDialog.h
ImplementationFile=ConnectionStatusDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_IMPEDANCE_DETECTIVE_DIALOG]
Type=1
Class=CImpedanceDetectiveDialog
ControlCount=71
Control1=IDC_START_DETECTIVE,button,1342242816
Control2=IDC_STOP_DETECTIVE,button,1342242816
Control3=IDC_OK,button,1342242816
Control4=IDC_STATIC,static,1342308865
Control5=IDC_IMP_Fp1,edit,1350633600
Control6=IDC_STATIC,static,1342308865
Control7=IDC_IMP_Fp2,edit,1350633600
Control8=IDC_STATIC,static,1342308865
Control9=IDC_IMP_F3,edit,1350633600
Control10=IDC_STATIC,static,1342308865
Control11=IDC_IMP_Fc3,edit,1350633600
Control12=IDC_STATIC,static,1342308865
Control13=IDC_IMP_C3,edit,1350633600
Control14=IDC_STATIC,static,1342308865
Control15=IDC_IMP_Cp3,edit,1350633600
Control16=IDC_STATIC,static,1342308865
Control17=IDC_IMP_P3,edit,1350633600
Control18=IDC_STATIC,static,1342308865
Control19=IDC_IMP_F4,edit,1350633600
Control20=IDC_STATIC,static,1342308865
Control21=IDC_IMP_Fc4,edit,1350633600
Control22=IDC_STATIC,static,1342308865
Control23=IDC_IMP_C4,edit,1350633600
Control24=IDC_STATIC,static,1342308865
Control25=IDC_IMP_Cp4,edit,1350633600
Control26=IDC_STATIC,static,1342308865
Control27=IDC_IMP_P4,edit,1350633600
Control28=IDC_STATIC,static,1342308865
Control29=IDC_IMP_O1,edit,1350633600
Control30=IDC_STATIC,static,1342308865
Control31=IDC_IMP_O2,edit,1350633600
Control32=IDC_STATIC,static,1342308865
Control33=IDC_IMP_Fz,edit,1350633600
Control34=IDC_STATIC,static,1342308865
Control35=IDC_IMP_Fcz,edit,1350633600
Control36=IDC_STATIC,static,1342308865
Control37=IDC_IMP_Cz,edit,1350633600
Control38=IDC_STATIC,static,1342308865
Control39=IDC_IMP_Cpz,edit,1350633600
Control40=IDC_STATIC,static,1342308865
Control41=IDC_IMP_Pz,edit,1350633600
Control42=IDC_STATIC,static,1342308865
Control43=IDC_IMP_Oz,edit,1350633600
Control44=IDC_STATIC,static,1342308865
Control45=IDC_IMP_F8,edit,1350633600
Control46=IDC_STATIC,static,1342308865
Control47=IDC_IMP_T4,edit,1350633600
Control48=IDC_STATIC,static,1342308865
Control49=IDC_IMP_Tp8,edit,1350633600
Control50=IDC_STATIC,static,1342308865
Control51=IDC_IMP_T6,edit,1350633600
Control52=IDC_STATIC,static,1342308865
Control53=IDC_IMP_Pg2,edit,1350633600
Control54=IDC_STATIC,static,1342308865
Control55=IDC_IMP_F7,edit,1350633600
Control56=IDC_STATIC,static,1342308865
Control57=IDC_IMP_T3,edit,1350633600
Control58=IDC_STATIC,static,1342308865
Control59=IDC_IMP_Tp7,edit,1350633600
Control60=IDC_STATIC,static,1342308865
Control61=IDC_IMP_T5,edit,1350633600
Control62=IDC_STATIC,static,1342308865
Control63=IDC_IMP_Pg1,edit,1350633600
Control64=IDC_STATIC,static,1342308865
Control65=IDC_IMP_A2,edit,1350633600
Control66=IDC_STATIC,static,1342308865
Control67=IDC_IMP_A1,edit,1350633600
Control68=IDC_STATIC,static,1342308865
Control69=IDC_IMP_Ft7,edit,1350633600
Control70=IDC_STATIC,static,1342308865
Control71=IDC_IMP_Ft8,edit,1350633600

[CLS:CImpedanceDetectiveDialog]
Type=0
HeaderFile=ImpedanceDetectiveDialog.h
ImplementationFile=ImpedanceDetectiveDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CImpedanceDetectiveDialog

[DLG:IDD_CHANNELS_SETUP_DIALOG]
Type=1
Class=CChannelsSetupDialog
ControlCount=226
Control1=IDC_CHECK1,button,1342242819
Control2=IDC_COMBOHIGHFRE_Fp1,combobox,1344340226
Control3=IDC_STATIC,static,1342308865
Control4=IDC_STATIC,static,1342308865
Control5=IDC_COMBOWORKFRE_Fp1,combobox,1344340226
Control6=IDC_STATIC,static,1342308865
Control7=IDC_COMBOTIMEC_Fp1,combobox,1344340226
Control8=IDC_CHECK2,button,1342242819
Control9=IDC_COMBOHIGHFRE_Fp2,combobox,1344340226
Control10=IDC_STATIC,static,1342308865
Control11=IDC_STATIC,static,1342308865
Control12=IDC_COMBOWORKFRE_Fp2,combobox,1344340226
Control13=IDC_STATIC,static,1342308865
Control14=IDC_COMBOTIMEC_Fp2,combobox,1344340226
Control15=IDC_CHECK3,button,1342242819
Control16=IDC_COMBOHIGHFRE_F3,combobox,1344340226
Control17=IDC_STATIC,static,1342308865
Control18=IDC_STATIC,static,1342308865
Control19=IDC_COMBOWORKFRE_F3,combobox,1344340226
Control20=IDC_STATIC,static,1342308865
Control21=IDC_COMBOTIMEC_F3,combobox,1344340226
Control22=IDC_CHECK4,button,1342242819
Control23=IDC_COMBOHIGHFRE_F4,combobox,1344340226
Control24=IDC_STATIC,static,1342308865
Control25=IDC_STATIC,static,1342308865
Control26=IDC_COMBOWORKFRE_F4,combobox,1344340226
Control27=IDC_STATIC,static,1342308865
Control28=IDC_COMBOTIMEC_F4,combobox,1344340226
Control29=IDC_CHECK5,button,1342242819
Control30=IDC_COMBOHIGHFRE_C3,combobox,1344340226
Control31=IDC_STATIC,static,1342308865
Control32=IDC_STATIC,static,1342308865
Control33=IDC_COMBOWORKFRE_C3,combobox,1344340226
Control34=IDC_STATIC,static,1342308865
Control35=IDC_COMBOTIMEC_C3,combobox,1344340226
Control36=IDC_CHECK6,button,1342242819
Control37=IDC_COMBOHIGHFRE_C4,combobox,1344340226
Control38=IDC_STATIC,static,1342308865
Control39=IDC_STATIC,static,1342308865
Control40=IDC_COMBOWORKFRE_C4,combobox,1344340226
Control41=IDC_STATIC,static,1342308865
Control42=IDC_COMBOTIMEC_C4,combobox,1344340226
Control43=IDC_CHECK7,button,1342242819
Control44=IDC_COMBOHIGHFRE_P3,combobox,1344340226
Control45=IDC_STATIC,static,1342308865
Control46=IDC_STATIC,static,1342308865
Control47=IDC_COMBOWORKFRE_P3,combobox,1344340226
Control48=IDC_STATIC,static,1342308865
Control49=IDC_COMBOTIMEC_P3,combobox,1344340226
Control50=IDC_CHECK8,button,1342242819
Control51=IDC_COMBOHIGHFRE_P4,combobox,1344340226
Control52=IDC_STATIC,static,1342308865
Control53=IDC_STATIC,static,1342308865
Control54=IDC_COMBOWORKFRE_P4,combobox,1344340226
Control55=IDC_STATIC,static,1342308865
Control56=IDC_COMBOTIMEC_P4,combobox,1344340226
Control57=IDC_CHECK9,button,1342242819
Control58=IDC_COMBOHIGHFRE_O1,combobox,1344340226
Control59=IDC_STATIC,static,1342308865
Control60=IDC_STATIC,static,1342308865
Control61=IDC_COMBOWORKFRE_O1,combobox,1344340226
Control62=IDC_STATIC,static,1342308865
Control63=IDC_COMBOTIMEC_O1,combobox,1344340226
Control64=IDC_CHECK10,button,1342242819
Control65=IDC_COMBOHIGHFRE_O2,combobox,1344340226
Control66=IDC_STATIC,static,1342308865
Control67=IDC_STATIC,static,1342308865
Control68=IDC_COMBOWORKFRE_O2,combobox,1344340226
Control69=IDC_STATIC,static,1342308865
Control70=IDC_COMBOTIMEC_O2,combobox,1344340226
Control71=IDC_CHECK11,button,1342242819
Control72=IDC_COMBOHIGHFRE_F7,combobox,1344340226
Control73=IDC_STATIC,static,1342308865
Control74=IDC_STATIC,static,1342308865
Control75=IDC_COMBOWORKFRE_F7,combobox,1344340226
Control76=IDC_STATIC,static,1342308865
Control77=IDC_COMBOTIMEC_F7,combobox,1344340226
Control78=IDC_CHECK12,button,1342242819
Control79=IDC_COMBOHIGHFRE_F8,combobox,1344340226
Control80=IDC_STATIC,static,1342308865
Control81=IDC_STATIC,static,1342308865
Control82=IDC_COMBOWORKFRE_F8,combobox,1344340226
Control83=IDC_STATIC,static,1342308865
Control84=IDC_COMBOTIMEC_F8,combobox,1344340226
Control85=IDC_CHECK13,button,1342242819
Control86=IDC_COMBOHIGHFRE_T3,combobox,1344340226
Control87=IDC_STATIC,static,1342308865
Control88=IDC_STATIC,static,1342308865
Control89=IDC_COMBOWORKFRE_T3,combobox,1344340226
Control90=IDC_STATIC,static,1342308865
Control91=IDC_COMBOTIMEC_T3,combobox,1344340226
Control92=IDC_CHECK14,button,1342242819
Control93=IDC_COMBOHIGHFRE_T4,combobox,1344340226
Control94=IDC_STATIC,static,1342308865
Control95=IDC_STATIC,static,1342308865
Control96=IDC_COMBOWORKFRE_T4,combobox,1344340226
Control97=IDC_STATIC,static,1342308865
Control98=IDC_COMBOTIMEC_T4,combobox,1344340226
Control99=IDC_CHECK15,button,1342242819
Control100=IDC_COMBOHIGHFRE_T5,combobox,1344340226
Control101=IDC_STATIC,static,1342308865
Control102=IDC_STATIC,static,1342308865
Control103=IDC_COMBOWORKFRE_T5,combobox,1344340226
Control104=IDC_STATIC,static,1342308865
Control105=IDC_COMBOTIMEC_T5,combobox,1344340226
Control106=IDC_CHECK16,button,1342242819
Control107=IDC_COMBOHIGHFRE_T6,combobox,1344340226
Control108=IDC_STATIC,static,1342308865
Control109=IDC_STATIC,static,1342308865
Control110=IDC_COMBOWORKFRE_T6,combobox,1344340226
Control111=IDC_STATIC,static,1342308865
Control112=IDC_COMBOTIMEC_T6,combobox,1344340226
Control113=IDC_CHECK17,button,1342242819
Control114=IDC_COMBOHIGHFRE_Fz,combobox,1344340226
Control115=IDC_STATIC,static,1342308865
Control116=IDC_STATIC,static,1342308865
Control117=IDC_COMBOWORKFRE_Fz,combobox,1344340226
Control118=IDC_STATIC,static,1342308865
Control119=IDC_COMBOTIMEC_Fz,combobox,1344340226
Control120=IDC_CHECK18,button,1342242819
Control121=IDC_COMBOHIGHFRE_Cz,combobox,1344340226
Control122=IDC_STATIC,static,1342308865
Control123=IDC_STATIC,static,1342308865
Control124=IDC_COMBOWORKFRE_Cz,combobox,1344340226
Control125=IDC_STATIC,static,1342308865
Control126=IDC_COMBOTIMEC_Cz,combobox,1344340226
Control127=IDC_CHECK19,button,1342242819
Control128=IDC_COMBOHIGHFRE_Pz,combobox,1344340226
Control129=IDC_STATIC,static,1342308865
Control130=IDC_STATIC,static,1342308865
Control131=IDC_COMBOWORKFRE_Pz,combobox,1344340226
Control132=IDC_STATIC,static,1342308865
Control133=IDC_COMBOTIMEC_Pz,combobox,1344340226
Control134=IDC_CHECK20,button,1342242819
Control135=IDC_COMBOHIGHFRE_Fc3,combobox,1344340226
Control136=IDC_STATIC,static,1342308865
Control137=IDC_STATIC,static,1342308865
Control138=IDC_COMBOWORKFRE_Fc3,combobox,1344340226
Control139=IDC_STATIC,static,1342308865
Control140=IDC_COMBOTIMEC_Fc3,combobox,1344340226
Control141=IDC_CHECK21,button,1342242819
Control142=IDC_COMBOHIGHFRE_Fc4,combobox,1344340226
Control143=IDC_STATIC,static,1342308865
Control144=IDC_STATIC,static,1342308865
Control145=IDC_COMBOWORKFRE_Fc4,combobox,1344340226
Control146=IDC_STATIC,static,1342308865
Control147=IDC_COMBOTIMEC_Fc4,combobox,1344340226
Control148=IDC_CHECK22,button,1342242819
Control149=IDC_COMBOHIGHFRE_Cp3,combobox,1344340226
Control150=IDC_STATIC,static,1342308865
Control151=IDC_STATIC,static,1342308865
Control152=IDC_COMBOWORKFRE_Cp3,combobox,1344340226
Control153=IDC_STATIC,static,1342308865
Control154=IDC_COMBOTIMEC_Cp3,combobox,1344340226
Control155=IDC_CHECK23,button,1342242819
Control156=IDC_COMBOHIGHFRE_Cp4,combobox,1344340226
Control157=IDC_STATIC,static,1342308865
Control158=IDC_STATIC,static,1342308865
Control159=IDC_COMBOWORKFRE_Cp4,combobox,1344340226
Control160=IDC_STATIC,static,1342308865
Control161=IDC_COMBOTIMEC_Cp4,combobox,1344340226
Control162=IDC_CHECK24,button,1342242819
Control163=IDC_COMBOHIGHFRE_Ft7,combobox,1344340226
Control164=IDC_STATIC,static,1342308865
Control165=IDC_STATIC,static,1342308865
Control166=IDC_COMBOWORKFRE_Ft7,combobox,1344340226
Control167=IDC_STATIC,static,1342308865
Control168=IDC_COMBOTIMEC_Ft7,combobox,1344340226
Control169=IDC_CHECK25,button,1342242819
Control170=IDC_COMBOHIGHFRE_Ft8,combobox,1344340226
Control171=IDC_STATIC,static,1342308865
Control172=IDC_STATIC,static,1342308865
Control173=IDC_COMBOWORKFRE_Ft8,combobox,1344340226
Control174=IDC_STATIC,static,1342308865
Control175=IDC_COMBOTIMEC_Ft8,combobox,1344340226
Control176=IDC_CHECK26,button,1342242819
Control177=IDC_COMBOHIGHFRE_Tp7,combobox,1344340226
Control178=IDC_STATIC,static,1342308865
Control179=IDC_STATIC,static,1342308865
Control180=IDC_COMBOWORKFRE_Tp7,combobox,1344340226
Control181=IDC_STATIC,static,1342308865
Control182=IDC_COMBOTIMEC_Tp7,combobox,1344340226
Control183=IDC_CHECK27,button,1342242819
Control184=IDC_COMBOHIGHFRE_Tp8,combobox,1344340226
Control185=IDC_STATIC,static,1342308865
Control186=IDC_STATIC,static,1342308865
Control187=IDC_COMBOWORKFRE_Tp8,combobox,1344340226
Control188=IDC_STATIC,static,1342308865
Control189=IDC_COMBOTIMEC_Tp8,combobox,1344340226
Control190=IDC_CHECK28,button,1342242819
Control191=IDC_COMBOHIGHFRE_Fcz,combobox,1344340226
Control192=IDC_STATIC,static,1342308865
Control193=IDC_STATIC,static,1342308865
Control194=IDC_COMBOWORKFRE_Fcz,combobox,1344340226
Control195=IDC_STATIC,static,1342308865
Control196=IDC_COMBOTIMEC_Fcz,combobox,1344340226
Control197=IDC_CHECK29,button,1342242819
Control198=IDC_COMBOHIGHFRE_Cpz,combobox,1344340226
Control199=IDC_STATIC,static,1342308865
Control200=IDC_STATIC,static,1342308865
Control201=IDC_COMBOWORKFRE_Cpz,combobox,1344340226
Control202=IDC_STATIC,static,1342308865
Control203=IDC_COMBOTIMEC_Cpz,combobox,1344340226
Control204=IDC_CHECK30,button,1342242819
Control205=IDC_COMBOHIGHFRE_Oz,combobox,1344340226
Control206=IDC_STATIC,static,1342308865
Control207=IDC_STATIC,static,1342308865
Control208=IDC_COMBOWORKFRE_Oz,combobox,1344340226
Control209=IDC_STATIC,static,1342308865
Control210=IDC_COMBOTIMEC_Oz,combobox,1344340226
Control211=IDC_CHECK31,button,1342242819
Control212=IDC_COMBOHIGHFRE_Pg1,combobox,1344340226
Control213=IDC_STATIC,static,1342308865
Control214=IDC_STATIC,static,1342308865
Control215=IDC_COMBOWORKFRE_Pg1,combobox,1344340226
Control216=IDC_STATIC,static,1342308865
Control217=IDC_COMBOTIMEC_Pg1,combobox,1344340226
Control218=IDC_CHECK32,button,1342242819
Control219=IDC_COMBOHIGHFRE_Pg2,combobox,1344340226
Control220=IDC_STATIC,static,1342308865
Control221=IDC_STATIC,static,1342308865
Control222=IDC_COMBOWORKFRE_Pg2,combobox,1344340226
Control223=IDC_STATIC,static,1342308865
Control224=IDC_COMBOTIMEC_Pg2,combobox,1344340226
Control225=IDC_OK,button,1342242816
Control226=IDC_BACKSET,button,1342242816

[CLS:CChannelsSetupDialog]
Type=0
HeaderFile=ChannelsSetupDialog.h
ImplementationFile=ChannelsSetupDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CHECK1
VirtualFilter=dWC

[DLG:IDD_PARADIGM_SETUP_DIALOG]
Type=1
Class=CParadigmSetupDialog
ControlCount=7
Control1=IDC_STATIC,static,1342308865
Control2=IDC_ADD_ACTIVITY,button,1342242816
Control3=IDC_OK,button,1342242816
Control4=IDC_RESET,button,1342242816
Control5=IDC_LISTACS,SysListView32,1350631425
Control6=IDC_REPEAT,button,1342242816
Control7=IDC_COMBO1,combobox,1344340226

[CLS:CParadigmSetupDialog]
Type=0
HeaderFile=ParadigmSetupDialog.h
ImplementationFile=ParadigmSetupDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMBO1

[DLG:IDD_NEW_ACTIVITY_DIALOG]
Type=1
Class=CNewActivityDialog
ControlCount=8
Control1=IDC_STATIC,static,1342308866
Control2=IDC_NEW_AC,edit,1350631552
Control3=IDC_STATIC,static,1342308866
Control4=IDC_NEW_ACTEXT,edit,1350631552
Control5=IDC_OK,button,1342242816
Control6=IDC_CANCEL,button,1342242816
Control7=IDC_STATIC,static,1342308866
Control8=IDC_NEW_TAG,edit,1350631552

[CLS:CNewActivityDialog]
Type=0
HeaderFile=NewActivityDialog.h
ImplementationFile=NewActivityDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_NEW_AC2
VirtualFilter=dWC

[DLG:IDD_ADD_ACTIVITY_DIALOG]
Type=1
Class=CAddActivityDialog
ControlCount=12
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308865
Control3=IDC_STARTTIME,edit,1350633600
Control4=IDC_STATIC,static,1342308865
Control5=IDC_ENDTIME,edit,1350631552
Control6=IDC_STATIC,static,1342308865
Control7=IDC_COMBO_ACS,combobox,1344340226
Control8=IDC_OK,button,1342242816
Control9=IDC_CANCEL,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_ADD_NEW,button,1342242816
Control12=IDC_ACRESET,button,1342242816

[CLS:CAddActivityDialog]
Type=0
HeaderFile=AddActivityDialog.h
ImplementationFile=AddActivityDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_STARTTIME

[CLS:CWaveView]
Type=0
HeaderFile=WaveView.h
ImplementationFile=WaveView.cpp
BaseClass=CScrollView
Filter=C

[DLG:IDD_DEVICE_INFO_DIALOG]
Type=1
Class=CDeviceInfoDialog
ControlCount=10
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308866
Control3=IDC_CHANNELS_COUNT,edit,1350633600
Control4=IDC_STATIC,static,1342308866
Control5=IDC_DEVICE_TYPE,edit,1350633600
Control6=IDC_STATIC,static,1342308866
Control7=IDC_DEVICE_ID,edit,1350633600
Control8=IDC_STATIC,static,1342308866
Control9=IDC_SWITCH_NO,edit,1350633600
Control10=IDC_OK,button,1342242816

[CLS:CDeviceInfoDialog]
Type=0
HeaderFile=DeviceInfoDialog.h
ImplementationFile=DeviceInfoDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[DLG:IDD_PARADIGM_SHOW]
Type=1
Class=CParadigmShowDialog
ControlCount=0

[CLS:CParadigmShowDialog]
Type=0
HeaderFile=ParadigmShowDialog.h
ImplementationFile=ParadigmShowDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_EEGWAVE_DIALOG]
Type=1
Class=CEEGWaveDialog
ControlCount=22
Control1=IDC_DRAW0,MyDrawPad,1342242816
Control2=IDC_DRAW1,MyDrawPad,1342242816
Control3=IDC_DRAW2,MyDrawPad,1342242816
Control4=IDC_DRAW3,MyDrawPad,1342242816
Control5=IDC_DRAW4,MyDrawPad,1342242816
Control6=IDC_DRAW5,MyDrawPad,1342242816
Control7=IDC_DRAW6,MyDrawPad,1342242816
Control8=IDC_DRAW7,MyDrawPad,1342242816
Control9=IDC_DRAW8,MyDrawPad,1342242816
Control10=IDC_DRAW9,MyDrawPad,1342242816
Control11=IDC_DRAW10,MyDrawPad,1342242816
Control12=IDC_DRAW11,MyDrawPad,1342242816
Control13=IDC_LAST_PAGE,button,1342242816
Control14=IDC_NEXT_PAGE,button,1342242816
Control15=IDC_CANCEL,button,1342242816
Control16=IDC_COMBO1,combobox,1344340226
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_COMBO2,combobox,1344340226
Control20=IDC_SWITCHSCALE,button,1342242816
Control21=IDC_COLLECT,button,1342242816
Control22=IDC_STOP_COLLECT,button,1342242816

[CLS:CEEGWaveDialog]
Type=0
HeaderFile=EEGWaveDialog.h
ImplementationFile=EEGWaveDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO1
VirtualFilter=dWC

[CLS:CDrawPand]
Type=0
HeaderFile=DrawPand.h
ImplementationFile=DrawPand.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC

[DLG:IDD_TCPIP_SETUP_DIALOG]
Type=1
Class=CTCPIPSetupDialog
ControlCount=8
Control1=IDC_STATIC,button,1342177287
Control2=IDC_EDIT_IPS,edit,1350633604
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_PORT,edit,1350639744
Control5=IDC_BTN_OK,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_IP_ADDR,edit,1350631552
Control8=IDC_STATIC,static,1342308352

[CLS:CTCPIPSetupDialog]
Type=0
HeaderFile=TCPIPSetupDialog.h
ImplementationFile=TCPIPSetupDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTCPIPSetupDialog

[DLG:IDD_ONLINESYSTEM1_DIALOG]
Type=1
Class=COnlineSystem1
ControlCount=4
Control1=IDC_BUTTON_START,button,1342242816
Control2=IDC_EDIT_INSTRUCTION,edit,1350633600
Control3=IDC_STATIC,static,1342308352
Control4=IDC_ON1_MOVING_CUBE,static,1342177284

[CLS:COnlineSystem1]
Type=0
HeaderFile=OnlineSystem1.h
ImplementationFile=OnlineSystem1.cpp
BaseClass=CDialog
Filter=D
LastObject=COnlineSystem1
VirtualFilter=dWC
