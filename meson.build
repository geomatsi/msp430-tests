project('msp430 tests', ['c'])

assert(meson.is_cross_build(), 'Use cross-build for msp430 target')

test1 = executable('blink',
	'src/blink.c',
	build_by_default : true,
)

test2 = executable('pir',
	'src/pir.c',
	build_by_default : false,

)

mspdebug = find_program('mspdebug')

run_target('flash',
	command : [mspdebug, 'rf2500', 'prog @0@'.format(test1.full_path())],
	depends : test1
)
