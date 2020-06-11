module.exports = {
  distanceFromBottom: function() {
    // console.log("position atual", Math.floor(
    //   document.body.clientHeight - (window.scrollY + window.innerHeight)
    // ));
    console.log('scrolling', Math.floor(window.scrollY))
    return Math.floor(
      window.scrollY
    );
  },
  scroller: function() {
    if((window.innerHeight + window.scrollY) >= document.body.scrollHeight) {
      console.log('page bottom');
      return true;
    }
    return false;
  }
};
