extern "C" {
#include <stdio.h>

#include <libpdbg.h>
}

#include "libipl.H"
#include "libipl_internal.H"

static void ipl_pre2(void)
{
	struct pdbg_target *pib;

	pdbg_for_each_class_target("pib", pib)
		pdbg_target_probe(pib);
}

static int ipl_proc_sbe_ld_image(void)
{
	return -1;
}

static int ipl_proc_sbe_attr_setup(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 2);

	return rc;
}

static int ipl_proc_sbe_tp_chiplet_init1(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 3);

	return rc;
}

static int ipl_proc_sbe_tp_gptr_time_initf(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 4);

	return rc;
}

static int ipl_proc_sbe_dft_probe_setup_1(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 5);

	return rc;
}

static int ipl_proc_sbe_npll_initf(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 6);

	return rc;
}

static int ipl_proc_sbe_npll_setup(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 7);

	return rc;
}

static int ipl_proc_sbe_tp_switch_gears(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 8);

	return rc;
}

static int ipl_proc_sbe_clock_test(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 9);

	return rc;
}

static int ipl_proc_sbe_tp_chiplet_reset(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 10);

	return rc;
}

static int ipl_proc_sbe_tp_repr_initf(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 11);

	return rc;
}

static int ipl_proc_sbe_tp_chiplet_init2(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 12);

	return rc;
}

static int ipl_proc_sbe_setup_tp_abist(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 13);

	return rc;
}

static int ipl_proc_sbe_tp_arrayinit(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 14);

	return rc;
}

static int ipl_proc_sbe_tp_initf(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 15);

	return rc;
}

static int ipl_proc_sbe_dft_probe_setup_2(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 16);

	return rc;
}

static int ipl_proc_sbe_tp_chiplet_init3(void)
{
	struct pdbg_target *pib;
	int rc = 0;

	pdbg_for_each_class_target("pib", pib)
		rc |= sbe_istep(pib, 2, 17);

	return rc;
}

static struct ipl_step ipl2[] = {
	{ IPL_DEF(proc_sbe_ld_image),           2,  1,  true,  true  },
	{ IPL_DEF(proc_sbe_attr_setup),         2,  2,  true,  true  },
	{ IPL_DEF(proc_sbe_tp_chiplet_init1),   2,  3,  true,  true  },
	{ IPL_DEF(proc_sbe_tp_gptr_time_initf), 2,  4,  true,  true  },
	{ IPL_DEF(proc_sbe_dft_probe_setup_1),  2,  5,  true,  false },
	{ IPL_DEF(proc_sbe_npll_initf),         2,  6,  true,  true  },
	{ IPL_DEF(proc_sbe_npll_setup),         2,  7,  true,  true  },
	{ IPL_DEF(proc_sbe_tp_switch_gears),    2,  8,  true,  true  },
	{ IPL_DEF(proc_sbe_clock_test),         2,  9,  true,  true  },
	{ IPL_DEF(proc_sbe_tp_chiplet_reset),   2, 10,  true,  true  },
	{ IPL_DEF(proc_sbe_tp_repr_initf),      2, 11,  true,  true  },
	{ IPL_DEF(proc_sbe_tp_chiplet_init2),   2, 12,  true,  true  },
	{ IPL_DEF(proc_sbe_setup_tp_abist),     2, 13,  true,  false },
	{ IPL_DEF(proc_sbe_tp_arrayinit),       2, 14,  true,  true  },
	{ IPL_DEF(proc_sbe_tp_initf),           2, 15,  true,  true  },
	{ IPL_DEF(proc_sbe_dft_probe_setup_2),  2, 16,  true,  false },
	{ IPL_DEF(proc_sbe_tp_chiplet_init3),   2, 17,  true,  true  },
	{ NULL, NULL, -1, -1, false, false },
};

__attribute__((constructor))
static void ipl_register_ipl2(void)
{
	ipl_register(2, ipl2, ipl_pre2);
}
