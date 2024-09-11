
#ifndef ADMAT_EXPORT_H
#define ADMAT_EXPORT_H

#ifdef ADMAT_STATIC_DEFINE
#  define ADMAT_EXPORT
#  define ADMAT_NO_EXPORT
#else
#  ifndef ADMAT_EXPORT
#    ifdef admat_admat_EXPORTS
        /* We are building this library */
#      define ADMAT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ADMAT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ADMAT_NO_EXPORT
#    define ADMAT_NO_EXPORT 
#  endif
#endif

#ifndef ADMAT_DEPRECATED
#  define ADMAT_DEPRECATED __declspec(deprecated)
#endif

#ifndef ADMAT_DEPRECATED_EXPORT
#  define ADMAT_DEPRECATED_EXPORT ADMAT_EXPORT ADMAT_DEPRECATED
#endif

#ifndef ADMAT_DEPRECATED_NO_EXPORT
#  define ADMAT_DEPRECATED_NO_EXPORT ADMAT_NO_EXPORT ADMAT_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ADMAT_NO_DEPRECATED
#    define ADMAT_NO_DEPRECATED
#  endif
#endif

#endif /* ADMAT_EXPORT_H */
