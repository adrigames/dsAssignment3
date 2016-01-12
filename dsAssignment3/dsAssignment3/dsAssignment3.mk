##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=dsAssignment3
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\R\Documents\LabDS\Practice 3\dsAssignment3\dsAssignment3"
ProjectPath            := "C:\Users\R\Documents\LabDS\Practice 3\dsAssignment3\dsAssignment3\dsAssignment3"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=R
Date                   :=12/01/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="dsAssignment3.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/simpleNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/complexNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/simpleBST.cpp$(ObjectSuffix) $(IntermediateDirectory)/complexBST.cpp$(ObjectSuffix) $(IntermediateDirectory)/IOHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainHandler.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 3/dsAssignment3/dsAssignment3/dsAssignment3/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/simpleNode.cpp$(ObjectSuffix): simpleNode.cpp $(IntermediateDirectory)/simpleNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 3/dsAssignment3/dsAssignment3/dsAssignment3/simpleNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/simpleNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simpleNode.cpp$(DependSuffix): simpleNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/simpleNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/simpleNode.cpp$(DependSuffix) -MM "simpleNode.cpp"

$(IntermediateDirectory)/simpleNode.cpp$(PreprocessSuffix): simpleNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/simpleNode.cpp$(PreprocessSuffix) "simpleNode.cpp"

$(IntermediateDirectory)/complexNode.cpp$(ObjectSuffix): complexNode.cpp $(IntermediateDirectory)/complexNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 3/dsAssignment3/dsAssignment3/dsAssignment3/complexNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/complexNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/complexNode.cpp$(DependSuffix): complexNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/complexNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/complexNode.cpp$(DependSuffix) -MM "complexNode.cpp"

$(IntermediateDirectory)/complexNode.cpp$(PreprocessSuffix): complexNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/complexNode.cpp$(PreprocessSuffix) "complexNode.cpp"

$(IntermediateDirectory)/simpleBST.cpp$(ObjectSuffix): simpleBST.cpp $(IntermediateDirectory)/simpleBST.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 3/dsAssignment3/dsAssignment3/dsAssignment3/simpleBST.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/simpleBST.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simpleBST.cpp$(DependSuffix): simpleBST.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/simpleBST.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/simpleBST.cpp$(DependSuffix) -MM "simpleBST.cpp"

$(IntermediateDirectory)/simpleBST.cpp$(PreprocessSuffix): simpleBST.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/simpleBST.cpp$(PreprocessSuffix) "simpleBST.cpp"

$(IntermediateDirectory)/complexBST.cpp$(ObjectSuffix): complexBST.cpp $(IntermediateDirectory)/complexBST.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 3/dsAssignment3/dsAssignment3/dsAssignment3/complexBST.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/complexBST.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/complexBST.cpp$(DependSuffix): complexBST.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/complexBST.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/complexBST.cpp$(DependSuffix) -MM "complexBST.cpp"

$(IntermediateDirectory)/complexBST.cpp$(PreprocessSuffix): complexBST.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/complexBST.cpp$(PreprocessSuffix) "complexBST.cpp"

$(IntermediateDirectory)/IOHandler.cpp$(ObjectSuffix): IOHandler.cpp $(IntermediateDirectory)/IOHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 3/dsAssignment3/dsAssignment3/dsAssignment3/IOHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IOHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IOHandler.cpp$(DependSuffix): IOHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IOHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IOHandler.cpp$(DependSuffix) -MM "IOHandler.cpp"

$(IntermediateDirectory)/IOHandler.cpp$(PreprocessSuffix): IOHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IOHandler.cpp$(PreprocessSuffix) "IOHandler.cpp"

$(IntermediateDirectory)/MainHandler.cpp$(ObjectSuffix): MainHandler.cpp $(IntermediateDirectory)/MainHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/R/Documents/LabDS/Practice 3/dsAssignment3/dsAssignment3/dsAssignment3/MainHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainHandler.cpp$(DependSuffix): MainHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainHandler.cpp$(DependSuffix) -MM "MainHandler.cpp"

$(IntermediateDirectory)/MainHandler.cpp$(PreprocessSuffix): MainHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainHandler.cpp$(PreprocessSuffix) "MainHandler.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


