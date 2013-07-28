var math = require('../math_native/build/Release/math_native');
module.exports = math.Vector3;
module.exports.prototype.projectOnVector = function () {

		var v1 = new math.Vector3();

		return function ( vector ) {

			v1.copy( vector ).normalize();
			var d = this.dot( v1 );
			return this.copy( v1 ).multiplyScalar( d );
		};
	}();
module.exports.prototype.projectOnPlane = function () {

		var v1 = new math.Vector3();

		return function ( planeNormal ) {

			v1.copy( this ).projectOnVector( planeNormal );

			return this.sub( v1 );

		}

	}();

module.exports.prototype.reflect = function () {

		var v1 = new math.Vector3();

		return function ( vector ) {

		    v1.copy( this ).projectOnVector( vector ).multiplyScalar( 2 );

		    return this.subVectors( v1, this );

		}

	}();