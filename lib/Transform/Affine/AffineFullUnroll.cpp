#include "lib/Transform/Affine/AffineFullUnroll.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/include/mlir/Pass/Pass.h"

namespace mlir {
namespace tutorial {

    using mlir::affine::AffineForOp;
    // using mlir::affine::;

void AffineFullUnrollPass::runOnOperation() {
    //affine: loop analysis dialect
    getOperation().walk([&](affine::AffineForOp op) {
        if (failed(affine::loopUnrollFull(op))) {
            op.emitError("Unrolling failed");
            signalPassFailure();
        }
    });

}

} // namespace tutorial
} // namespace mlir
