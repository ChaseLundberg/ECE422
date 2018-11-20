/* 
 * File:   heartbeat.h
 * Author: Chase_000
 *
 * Created on November 13, 2018, 4:04 PM
 */

#ifndef HEARTBEAT_H
#define	HEARTBEAT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define crfFLASH_INDEX             (0)
#define crf_HEART_BEAT_PRIORITY    (0)

/* The number of flash co-routines to create. */
#define mainNUM_FLASH_COROUTINES   (1)
    
    void taskHeartbeat_Init(unsigned portBASE_TYPE uxPriority);
    void taskHeartbeat_Execute(void);
    void prvMainCoRoutine(CoRoutineHandle_t xHandle, unsigned portBASE_TYPE uxIndex);



#ifdef	__cplusplus
}
#endif

#endif	/* HEARTBEAT_H */

