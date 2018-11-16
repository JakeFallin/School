
const volumeOfRectangularPrism = function volumeOfRectangularPrism(length, width, height) {
	
			if((isNaN(length)) || (isNaN(width)) || (isNaN(height))) {
				throw("Not a number Error");
			}
			if((length <= 0) || (width <= 0) || (height <= 0)) {
				throw("Number out of Bounds Error");
			}
			return length * width * height;
}


const surfaceAreaOfRectangularPrism = function surfaceAreaOfRectangularPrism(length, width, height) {

		if((isNaN(length)) || (isNaN(width)) || (isNaN(height))) {
			throw("Not a number Error");
		}
		if((length <= 0) || (width <= 0) || (height <= 0)) {
			throw("Number out of Bounds Error");
		}
		return (2 * ((width*length) + (height*length) + (height*width)));

}


const volumeOfSphere = function volumeOfSphere(radius) {

		if(isNaN(radius)) {
			throw("Not a number Error");
		}
		if(radius <= 0) {
			throw("Number out of Bounds Error");
		}
		return ((4/3) * (Math.PI) * (Math.pow(radius, 3)));

}


const surfaceAreaOfSphere = function surfaceAreaOfSphere(radius) {

		if(isNaN(radius)) {
			throw("Not a number Error");
		}
		if(radius <= 0) {
			throw("Number out of Bounds Error");
		}
		return (4 * (Math.PI) * (Math.pow(radius, 2)));

}


module.exports = {
    volumeOfRectangularPrism,
    surfaceAreaOfRectangularPrism,
    volumeOfSphere,
    surfaceAreaOfSphere
};
