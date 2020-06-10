module.exports = {
  distanceFromBottom: function() {
    // console.log("position atual", Math.floor(
    //   document.body.clientHeight - (window.scrollY + window.innerHeight)
    // ));
    return Math.floor(
      window.scrollY
    );
  },
};
