/******************************
** Tsunagari Tile Engine     **
** config.h                  **
** Copyright 2011 OmegaSDG   **
******************************/

#ifndef CONFIG_H
#define CONFIG_H

// === Default Configuration Settings ===
	/* Tsunagari config file. -- Command Line */
	#define CLIENT_CONF_FILE "./client.ini"
	
	/* Error verbosity level. -- Command Line */
	#define MESSAGE_MODE MM_DEBUG
	
	/* Milliseconds of button down before starting persistent input in
	   roguelike movement mode. -- Move to World Descriptor */
	#define ROGUELIKE_PERSIST_DELAY_INIT 500
	
	/* Milliseconds between persistent input sends in roguelike movement
	   mode. -- Move to World Descriptor */
	#define ROGUELIKE_PERSIST_DELAY_CONSECUTIVE 10
	
	/* Time to live in seconds for empty resource cache entries before they
	   are deleted. -- Command Line */
	#define CACHE_EMPTY_TTL 300
// ===

// === Platform Specifics ===
	/* Windows check. */
	#if defined(_Windows) && !defined(_WINDOWS)
		#define _WINDOWS 1
	#endif

	#if defined(_WINDOWS) && !defined(_Windows)
		#define _Windows 1
	#endif
	
	/* Fix snprintf for VisualC++. */
	#ifdef _MSC_VER
		#define snprintf _snprintf
	#endif
// ===

#endif

