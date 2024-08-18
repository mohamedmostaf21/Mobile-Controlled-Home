/*
 * SEV_cfg.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Mohamed
 */
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"

#include "SEV.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"


Sev_config SEV_ConfigSet[MAX_SEV_SEGMENT]= {    

    {   
            /* A */       /* B */        /* C */         /* D */        /* E */         /* F */         /* G */  
        {DIO_PIN_NUM_8, DIO_PIN_NUM_9, DIO_PIN_NUM_10, DIO_PIN_NUM_12, DIO_PIN_NUM_13, DIO_PIN_NUM_14, DIO_PIN_NUM_15},
        DIO_PIN_NUM_2,
        Common_Cathode
    }

    ,

    {       /* A */       /* B */        /* C */         /* D */        /* E */         /* F */         /* G */  
        {DIO_PIN_NUM_16, DIO_PIN_NUM_17, DIO_PIN_NUM_18, DIO_PIN_NUM_19, DIO_PIN_NUM_20, DIO_PIN_NUM_21, DIO_PIN_NUM_22},
        DIO_PIN_NUM_23,
        Common_Cathode
    }

};



