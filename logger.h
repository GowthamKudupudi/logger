/* 
 * File:   logger.h
 * Author: Gowtham
 *
 * Created on June 24, 2014, 2:25 PM
 */

#ifndef LOGGER_H
#define LOGGER_H

/**
 * 
 */
enum FF_LOG_TYPE {
	FFL_ERR = 1 << 0,
	FFL_WARN = 1 << 1,
	FFL_NOTICE = 1 << 2,
	FFL_DEBUG = 1 << 3,
	FFL_INFO = 1 << 4,
	FFL_PARSER = 1 << 5,
	FFL_HEADER = 1 << 6,
	FFL_EXT = 1 << 7,
	FFL_CLIENT = 1 << 8,
	FFL_LATENCY = 1 << 9
};
extern FF_LOG_TYPE fflAllowedType;
extern unsigned int fflAllowedLevel;
void SetLogType(FF_LOG_TYPE t);
void SetLogLevel(unsigned int l);

/**
 * initiate ff_log_type ff_log_level them in your project
 */
int _ff_log(FF_LOG_TYPE t, const char* format, ...);
int _ff_log(const char* func,
		FF_LOG_TYPE allowedType,
		FF_LOG_TYPE t,
		unsigned int allowedLevel,
		unsigned int l,
		const char* format, ...);
int _ff_log(FF_LOG_TYPE allowedType,
		FF_LOG_TYPE t,
		unsigned int allowedLevel,
		unsigned int l,
		const char* func,
		const char* file_name,
		int line_no,
		const char* format, ...);
int _ff_log_contnu(FF_LOG_TYPE allowedType, FF_LOG_TYPE t,
		unsigned int allowedLevel,
		unsigned int l,
		const char* format, ...);

/* notice, warn and log are always compiled in */
#define ffl_notice(level,...) _ff_log(__FUNCTION__, fflAllowedType, FFL_NOTICE, fflAllowedLevel, level, __VA_ARGS__)
#define ffl_warn(level,...) _ff_log(__FUNCTION__, fflAllowedType, FFL_WARN, fflAllowedLevel, level, __VA_ARGS__)
#define ffl_err(level,...) _ff_log(__FUNCTION__, fflAllowedType, FFL_ERR, fflAllowedLevel, level, __VA_ARGS__)
#define ffl_info(level,...) _ff_log(__FUNCTION__, fflAllowedType, FFL_INFO, fflAllowedLevel, level, __VA_ARGS__)

/*
 *  weaker logging can be deselected at configure time using --disable-debug
 *  that gets rid of the overhead of checking while keeping _warn and _err
 *  active
 */
#ifdef _DEBUG

#define ffl_debug(allowedType,allowedLevel,level,...) _ff_log(allowedType,FFL_DEBUG, allowedLevel, level, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__)
#define ffl_parser(...) _ff_log(FFL_PARSER, __VA_ARGS__)
#define ffl_header(...)  _ff_log(FFL_HEADER, __VA_ARGS__)
#define ffl_ext(...)  _ff_log(FFL_EXT, __VA_ARGS__)
#define ffl_client(...) _ff_log(FFL_CLIENT, __VA_ARGS__)
#define ffl_latency(...) _ff_log(FFL_LATENCY, __VA_ARGS__)
//void log_hexdump(void *buf, size_t len);

#else /* no debug */

#define ffl_debug(...)
#define ffl_parser(...)
#define ffl_header(...)
#define ffl_ext(...)
#define ffl_client(...)
#define ffl_latency(...)
//#define ffl_hexdump(a, b)

#endif

#define ffl_notice_contnu(level,...) _ff_log_contnu(allowedType,FFL_NOTICE, fflAllowedLevel, level, __VA_ARGS__)
#define ffl_warn_contnu(level,...) _ff_log_contnu(allowedType,FFL_WARN, fflAllowedLevel, level, __VA_ARGS__)
#define ffl_err_contnu(level,...) _ff_log_contnu(allowedType,FFL_ERR, fflAllowedLevel, level, __VA_ARGS__)
#define ffl_info_contnu(level,...) _ff_log_contnu(allowedType,FFL_INFO, fflAllowedLevel, level, __VA_ARGS__)

/*
 *  weaker logging can be deselected at configure time using --disable-debug
 *  that gets rid of the overhead of checking while keeping _warn and _err
 *  active
 */
#ifdef _DEBUG

#define ffl_debug_contnu(level,...) _ff_log_contnu(allowedType, FFL_DEBUG, allowedLevel, level, __VA_ARGS__)
#define ffl_parser_contnu(...) _ff_log_contnu(FFL_PARSER, __VA_ARGS__)
#define ffl_header_contnu(...)  _ff_log_contnu(FFL_HEADER, __VA_ARGS__)
#define ffl_ext_contnu(...)  _ff_log_contnu(FFL_EXT, __VA_ARGS__)
#define ffl_client_contnu(...) _ff_log_contnu(FFL_CLIENT, __VA_ARGS__)
#define ffl_latency_contnu(...) _ff_log_contnu(FFL_LATENCY, __VA_ARGS__)
//void log_hexdump(void *buf, size_t len);

#else /* no debug */

#define ffl_debug_contnu(...)
#define ffl_parser_contnu(...)
#define ffl_header_contnu(...)
#define ffl_ext_contnu(...)
#define ffl_client_contnu(...)
#define ffl_latency_contnu(...)
//#define ffl_hexdump_contnu(a, b)

#endif

bool _ffl_level(FF_LOG_TYPE allowedType, FF_LOG_TYPE t,
		unsigned int allowedLevel,
		unsigned int l);

#define ffl_notice_lvl(level) _ffl_level(FFL_NOTICE, level)
#define ffl_warn_lvl(level) _ffl_level(FFL_WARN, level)
#define ffl_err_lvl(level) _ffl_level(FFL_ERR, level)
#define ffl_debug_lvl(level) _ffl_level(FFL_DEBUG,  level)


#endif /* LOGGER_H */
