#ifndef PROMPT
#define PROMPT

static inline void _prt_int(long x)     { printf("%ld", x); }
static inline void _prt_int_ln(long x)  { printf("%ld\n", x); }

static inline void _prt_double(double x)    { printf("%g",  x); }
static inline void _prt_double_ln(double x) { printf("%g\n",x); }

static inline void _prt_char(char c)    { printf("%c",  c); }
static inline void _prt_char_ln(char c) { printf("%c\n",c); }

static inline void _prt_str(const char *s)      { printf("%s",  s); }
static inline void _prt_str_ln(const char *s)   { printf("%s\n",s); }

static inline void _prt_bool(int b)     { printf("%s",  b ? "true" : "false"); }
static inline void _prt_bool_ln(int b)  { printf("%s\n",b ? "true" : "false"); }

#define print(x) _Generic((x),                     \
        char:               _prt_char,            \
        signed char:        _prt_char,            \
        unsigned char:      _prt_char,            \
        int:                _prt_int,             \
        long:               _prt_int,             \
        long long:          _prt_int,             \
        float:              _prt_double,          \
        double:             _prt_double,          \
        long double:        _prt_double,          \
        _Bool:              _prt_bool,            \
        char *:             _prt_str,             \
        const char *:       _prt_str,             \
        default:            _prt_str              \
)(x)

#define printLine(x) _Generic((x),                 \
        char:               _prt_char_ln,         \
        signed char:        _prt_char_ln,         \
        unsigned char:      _prt_char_ln,         \
        int:                _prt_int_ln,          \
        long:               _prt_int_ln,          \
        long long:          _prt_int_ln,          \
        float:              _prt_double_ln,       \
        double:             _prt_double_ln,       \
        long double:        _prt_double_ln,       \
        _Bool:              _prt_bool_ln,         \
        char *:             _prt_str_ln,          \
        const char *:       _prt_str_ln,          \
        default:            _prt_str_ln           \
)(x)


#endif
