/*
 * =====================================================================================
 *
 *       Filename:  p_constants.h
 *
 *    Description:  Stores values used throughout project
 *
 *        Version:  0.1 ALPHA
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

 #ifndef p_constants
 #define p_constants

/*
 * ==============
 * Map constants
 * ==============
 */
#define M_WIDTH 16
#define M_HEIGHT 16

/*
 * =================
 * Object constants
 * =================
 */

// Air
#define AIR_RES 0
#define AIR_PWR 0
#define AIR_R 0
#define AIR_G 0
#define AIR_B 0

// Wall
#define WALL_RES 100
#define WALL_PWR 0
#define WALL_R 255
#define WALL_G 0
#define WALL_B 255

// Player
#define PLYR_RES 0
#define PLYR_PWR 5
#define PLYR_R 255
#define PLYR_G 255
#define PLYR_B 255

/*
 * ============
 * Arduino Pins
 * ============
 */
#define MATRIX_PIN 6
#define SD_PIN 53

#endif
