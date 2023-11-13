/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:53:19 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 16:16:44 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                to=42             */
/*   Created: 2023/10/30 14:34:55 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 14:40:25 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &original);
        ~Intern();
        Intern &operator=(const Intern &original);

        AForm *makeForm(const std::string &formName, const std::string &target);
};
