open NavbarStyles;

// type state = {menuIsActive: bool};

// type action =
//   | ToggleMenu;

[@react.component]
let make = () => {
  <div className=navbarContainer>
    <h1>{ReasonReact.string("Arthur")}</h1>
  </div>
};

  // let (state, dispatch) =
  //   React.useReducer(
  //     (state, action) =>
  //       switch (action) {
  //       | ToggleMenu => {menuIsActive: !state.menuIsActive}
  //       },
  //     {menuIsActive: false},
  //   );
  // <div className="hero-head">
  //   <nav id="topnav" className=topnavStyles>
  //     <div className="container">
  //       <div className=navbarBrand>
  //           <a className=subtitle> {ReasonReact.string("HearthReason")} </a>
  //         <span
  //           className={navbarBurger(state.menuIsActive)}
  //           onClick={_event => dispatch(ToggleMenu)}>
  //           <span />
  //           <span />
  //           <span />
  //         </span>
  //       </div>
  //       <div id="navbarMenu" className={navbarMenu(state.menuIsActive)}>
  //         <div className="navbar-end">
  //           <div className=navbarItem>
  //               <a> {ReasonReact.string("About")} </a>
  //           </div>
  //           <div className=navbarItem>
  //               <a> {ReasonReact.string("contact")} </a>
  //           </div>
  //         </div>
  //       </div>
  //     </div>
  //   </nav>
  // </div>;