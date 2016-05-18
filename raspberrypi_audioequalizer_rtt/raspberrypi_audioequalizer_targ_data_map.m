  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (raspberrypi_audioequalizer_P)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% raspberrypi_audioequalizer_P.CoeffsMatrix1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% raspberrypi_audioequalizer_P.CoeffsMatrix2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% raspberrypi_audioequalizer_P.CoeffsMatrix3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 10;
	
	  ;% raspberrypi_audioequalizer_P.SmoothCoefficientsLeakyIntegrat
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 15;
	
	  ;% raspberrypi_audioequalizer_P.SmoothCoefficientsLeakyIntegr_c
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 16;
	
	  ;% raspberrypi_audioequalizer_P.SmoothCoefficientsLeakyIntegr_k
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 17;
	
	  ;% raspberrypi_audioequalizer_P.a1_Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% raspberrypi_audioequalizer_P.a1_Gain_n
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% raspberrypi_audioequalizer_P.a1_Gain_o
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
	  ;% raspberrypi_audioequalizer_P.Gain_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (raspberrypi_audioequalizer_B)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% raspberrypi_audioequalizer_B.Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% raspberrypi_audioequalizer_B.BiquadFilter
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 4410;
	
	  ;% raspberrypi_audioequalizer_B.BiquadFilter_a
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 8820;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% raspberrypi_audioequalizer_B.Add
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% raspberrypi_audioequalizer_B.Add_o
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 5;
	
	  ;% raspberrypi_audioequalizer_B.BiquadFilter_m
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 10;
	
	  ;% raspberrypi_audioequalizer_B.Add_j
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 4420;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (raspberrypi_audioequalize_DWork)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% raspberrypi_audioequalize_DWork.FromWorkspace_PWORK.TimePtr
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% raspberrypi_audioequalize_DWork.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% raspberrypi_audioequalize_DWork.BiquadFilter_FILT_STATES
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 5;
	
	  ;% raspberrypi_audioequalize_DWork.UnitDelay_DSTATE_l
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 7;
	
	  ;% raspberrypi_audioequalize_DWork.BiquadFilter_FILT_STATES_d
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 12;
	
	  ;% raspberrypi_audioequalize_DWork.UnitDelay_DSTATE_m
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 14;
	
	  ;% raspberrypi_audioequalize_DWork.BiquadFilter_ZERO_STATES
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 19;
	
	  ;% raspberrypi_audioequalize_DWork.BiquadFilter_POLE_STATES
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% raspberrypi_audioequalize_DWork.FromWorkspace_IWORK.PrevIndex
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2763142580;
  targMap.checksum1 = 994019543;
  targMap.checksum2 = 71031852;
  targMap.checksum3 = 1511162319;

