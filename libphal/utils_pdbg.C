#include "log.H"
#include "phal_exception.H"
#include "utils_pdbg.H"

namespace openpower::phal::utils
{
namespace pdbg
{

using namespace openpower::phal::logging;
using namespace openpower::phal;

struct pdbg_target *getPibTarget(struct pdbg_target *proc)
{
	char path[16];
	sprintf(path, "/proc%d/pib", pdbg_target_index(proc));
	struct pdbg_target *pib = pdbg_target_from_path(nullptr, path);
	if (pib == nullptr) {
		log(level::ERROR, "Failed to get PIB target for(%s)",
		    pdbg_target_path(proc));
		throw pdbgError_t(exception::PDBG_TARGET_NOT_OPERATIONAL);
	}
	// Probe the target
	if (pdbg_target_probe(pib) != PDBG_TARGET_ENABLED) {
		log(level::ERROR, "PIB(%s) probe: fail to enable",
		    pdbg_target_path(pib));
		throw pdbgError_t(exception::PDBG_TARGET_NOT_OPERATIONAL);
	}
	return pib;
}

struct pdbg_target *getFsiTarget(struct pdbg_target *proc)
{
	char path[16];
	sprintf(path, "/proc%d/fsi", pdbg_target_index(proc));
	struct pdbg_target *fsi = pdbg_target_from_path(nullptr, path);
	if (fsi == nullptr) {
		log(level::ERROR, "Failed to get FSI target for(%s)",
		    pdbg_target_path(proc));
		throw pdbgError_t(exception::PDBG_TARGET_NOT_OPERATIONAL);
	}
	// Probe the target
	if (pdbg_target_probe(fsi) != PDBG_TARGET_ENABLED) {
		log(level::ERROR, "FSI(%s) probe: fail to enable",
		    pdbg_target_path(fsi));
		throw pdbgError_t(exception::PDBG_TARGET_NOT_OPERATIONAL);
	}
	return fsi;
}

} // namespace pdbg
} // namespace openpower::phal::utils
