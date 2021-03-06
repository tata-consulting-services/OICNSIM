/* -*- Mode:C++; c-file-style; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2016, TCS Research & Innovation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: Anirudh Morabagal <anirudhmk.2010@gmail.com>
 *          Suvrat Agrawal <suvrat.a@tcs.com>
 *
 */

#ifndef OICN_HEADER_H
#define OICN_HEADER_H

#include <stdint.h>
#include <string>
#include "ns3/header.h"
#include "ns3/type-name.h"

namespace ns3{

/**
 * \brief Class for Creating and Appending O-ICN Sublayer to a Packet
 *
 * This class has fields corresponding to those in a network UDP header
 * (port numbers, payload size, checksum) as well as methods for serialization
 * to and deserialization from a byte buffer.
 */

class OicnHeader : public Header
{
public:

  OicnHeader ();
  ~OicnHeader ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;
  void SetName(std::string name);
  std::string GetName(void);
  void SetRequest(void);
  void SetCachable(void);
  void SetNonCachable(void);
  uint32_t GetFirst4Bytes (void);

  private:

  void SetFirst4Bytes(uint32_t HeaderLength, bool reply, bool cachable);

  std::string m_name;
  uint32_t header_length;
  uint32_t first4bytes;

  static const uint32_t cachable_start = 4026531840;    //11110000000000000000000000000000
  static const uint32_t non_cachable_start = 2952790016;//10110000000000000000000000000000
  static const uint32_t request_start = 805306368;     //00110000000000000000000000000000

};
}
#endif
