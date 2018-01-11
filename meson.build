project('msp430 tests', 'c',
	version : '0.1',
	default_options : [ 'buildtype=minsize', 'c_std=c99' ],
)

assert(meson.is_cross_build(), 'Use cross-build for msp430 target')

mspdebug = find_program('mspdebug', required : true)
echo = find_program('echo', required : true)

incdir = include_directories('include')

progs = [
	['blink', ['src/blink.c'], 'LED example'],
	['pir', ['src/pir.c'], 'GPIO input example'],
]

targets = []

foreach p : progs
	e = executable(p[0], p[1],
		c_args : '-mmcu=msp430g2231',
		link_args : '-mmcu=msp430g2231',
		include_directories : incdir,
		build_by_default : false,
	)

	r = run_target('flash_' + p[0],
		command : [mspdebug, 'rf2500', 'prog @0@'.format(e.full_path())],
		depends : e,
	)

	targets += [p[0], 'flash_' + p[0]]
endforeach

run_target('list',
	command : [echo, targets],
)
