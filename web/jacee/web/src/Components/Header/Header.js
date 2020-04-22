import React from "react";
import NavbarPage from "./NavBar/NavBar";
import { ToastProvider } from "react-toast-notifications";

function Header() {
  return (
    <div className="Header">
      <ToastProvider autoDismiss autoDismissTimeout={6000}>
        <NavbarPage />
      </ToastProvider>
    </div>
  );
}

export default Header;
