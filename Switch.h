

// ***************** Switch1_Init() ****************
// Initialize the second switch to PB3 for Play/Pause
// Inputs: none
// Outputs: none
void Switch1_Init(void);

// ***************** Switch2_Init() ****************
// Initialize the third switch to PB2 for Rewind to beginning of song
// Inputs: none
// Outputs: none
void Switch2_Init(void);

// ***************** GPIOPortB_Handler() ****************
// Handler for any switches being pressed
// Makes use of a "play" flag to determine whether music should be turned off or on if switch 1 is pressed
// Resets music to beginning if switch 2 is pressed
// Inputs: none
// Outputs: none
void GPIOPortB_Handler(void);

void DelayWait10ms(int n);

static void GPIOArm(void);

void Timer2Arm(void);

void Timer2A_Handler(void);

int Get_ClearFlag(void);

void Set_ClearFlag(int flag);
